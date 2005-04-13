/*
 * parse.h 
 *
 * a Net::DNS like library for C
 * LibDNS Team @ NLnet Labs
 * (c) NLnet Labs, 2005
 * See the file LICENSE for the license
 */

#ifndef _PARSE_H_
#define _PARSE_H_

#include <ldns/common.h>
#include <ldns/buffer.h>


#define LDNS_PARSE_SKIP_SPACE		"\f\n\r\v"
#define LDNS_PARSE_NORMAL		" \f\n\r\t\v"
#define MAXLINE_LEN		512
#define MAXKEYWORD_LEN		32

/* 
 * get a token/char from the stream F
 * return 0 on error of EOF of F
 * return >0 length of what is read.
 * This function deals with ( and ) in the stream
 * and ignore \n when it finds them
 * if the limit == 0, don't use it
 * otherwise its the maximum returned dize
 */
ssize_t ldns_fget_token(FILE *f, char *token, const char *delim, size_t limit);

/* 
 * search for keyword and delim. Give everything back
 * after the keyword + k_del until we hit d_del
 */
ssize_t 
ldns_fget_keyword_data(FILE *f, const char *keyword, const char *k_del, char *data, const char *d_del);

/* 
 * get a token/char from the buffer b
 * return 0 on error of EOF of F
 * return >0 length of what is read.
 * This function deals with ( and ) in the stream
 * and ignore \n when it finds them
 * if the limit == 0, don't use it
 * otherwise its the maximum returned dize
 */
ssize_t ldns_bget_token(ldns_buffer *b, char *token, const char *delim, size_t limit);

/* 
 * search for keyword and delim. Give everything back
 * after the keyword + k_del until we hit d_del
 */
ssize_t 
ldns_bget_keyword_data(ldns_buffer *b, const char *keyword, const char *k_del, char *data, const char *d_del);

/* remove comments from a string. Comment = ';' until \n
 * replace ; until \n with spaces
 * return the new string
 */
char * ldns_str_remove_comment(char *str);

/*
 * Get the next character from a buffer. Advance the position
 * pointer with 1.
 * When end of buffer is reached return EOF
 */
int ldns_bgetc(ldns_buffer *buffer);

/**
 * Skip all of the characters in the given string in the buffer, moving
 * the position to the first character that is not in *s
 */
void ldns_bskipcs(ldns_buffer *buffer, const char *s);

/**
 * Skip all of the characters in the given string in the fp, moving
 * the position to the first character that is not in *s
 */
void ldns_fskipcs(FILE *fp, const char *s);






#endif /*  _PARSE_H */
