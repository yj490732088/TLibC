/* Generated by re2c 0.13.5 on Wed Apr 09 21:08:36 2014 */
#line 1 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
#include "protocol/tlibc_xlsx_reader.h"
#include "tlibc_xlsx_reader_sharedstring_l.h"
#include <string.h>
#include <errno.h>

#define YYGETCONDITION()  self->scanner.state
#define YYSETCONDITION(s) self->scanner.state = s
#define STATE(name)  yyc##name
#define BEGIN(state) YYSETCONDITION(STATE(state))
#define YYCURSOR self->scanner.cursor
#define YYLIMIT self->scanner.limit
#define YYMARKER self->scanner.marker
#define YYCTYPE char

tlibc_error_code_t tlibc_xlsx_reader_load_sharedstring(tlibc_xlsx_reader_t *self)
{
	char* str_begin = NULL;

	self->scanner.cursor = self->sharedstring_buff;
	self->scanner.limit = self->sharedstring_buff + self->sharedstring_buff_size;
	self->scanner.marker = self->scanner.cursor;
	self->scanner.state = yycINITIAL;
	self->sharedstring_begin_list = NULL;
	self->sharedstring_end_list = NULL;
	self->sharedstring_list_num = 0;

restart:
	if(YYCURSOR >= YYLIMIT)
	{
		return E_TLIBC_NOERROR;
	}


#line 37 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
{
	YYCTYPE yych;
	switch (YYGETCONDITION()) {
	case yycINITIAL: goto yyc_INITIAL;
	case yycIN_SST: goto yyc_IN_SST;
	case yycIN_SST_TAG: goto yyc_IN_SST_TAG;
	}
/* *********************************** */
yyc_INITIAL:

	yych = *YYCURSOR;
	switch (yych) {
	case '<':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 86 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{goto restart;}
#line 58 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
yy4:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'S':
	case 's':	goto yy5;
	default:	goto yy3;
	}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'S':
	case 's':	goto yy7;
	default:	goto yy6;
	}
yy6:
	YYCURSOR = YYMARKER;
	goto yy3;
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy8;
	default:	goto yy6;
	}
yy8:
	++YYCURSOR;
#line 36 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{BEGIN(IN_SST_TAG); goto restart;}
#line 87 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
/* *********************************** */
yyc_IN_SST:
	yych = *YYCURSOR;
	switch (yych) {
	case '<':	goto yy14;
	default:	goto yy12;
	}
yy12:
	++YYCURSOR;
yy13:
#line 86 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{goto restart;}
#line 100 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
yy14:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '/':	goto yy15;
	case 'T':
	case 't':	goto yy17;
	default:	goto yy13;
	}
yy15:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'S':
	case 's':	goto yy21;
	case 'T':
	case 't':	goto yy20;
	default:	goto yy16;
	}
yy16:
	YYCURSOR = YYMARKER;
	goto yy13;
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy18;
	default:	goto yy16;
	}
yy18:
	++YYCURSOR;
#line 70 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{
	str_begin = YYCURSOR;
	goto restart;
}
#line 134 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy26;
	default:	goto yy16;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'S':
	case 's':	goto yy22;
	default:	goto yy16;
	}
yy22:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy23;
	default:	goto yy16;
	}
yy23:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy24;
	default:	goto yy16;
	}
yy24:
	++YYCURSOR;
#line 82 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{
	BEGIN(INITIAL);
	goto restart;
}
#line 168 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
yy26:
	++YYCURSOR;
#line 75 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{
	self->sharedstring_begin_list[self->sharedstring_list_num] = str_begin;
	self->sharedstring_end_list[self->sharedstring_list_num] = YYCURSOR - 4;
	++self->sharedstring_list_num;
	goto restart;
}
#line 178 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
/* *********************************** */
yyc_IN_SST_TAG:
	yych = *YYCURSOR;
	switch (yych) {
	case 'C':
	case 'c':	goto yy32;
	default:	goto yy30;
	}
yy30:
	++YYCURSOR;
yy31:
#line 86 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{goto restart;}
#line 192 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
yy32:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'O':
	case 'o':	goto yy33;
	default:	goto yy31;
	}
yy33:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'U':
	case 'u':	goto yy35;
	default:	goto yy34;
	}
yy34:
	YYCURSOR = YYMARKER;
	goto yy31;
yy35:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'N':
	case 'n':	goto yy36;
	default:	goto yy34;
	}
yy36:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy37;
	default:	goto yy34;
	}
yy37:
	yych = *++YYCURSOR;
	switch (yych) {
	case '=':	goto yy38;
	default:	goto yy34;
	}
yy38:
	yych = *++YYCURSOR;
	switch (yych) {
	case '"':	goto yy39;
	default:	goto yy34;
	}
yy39:
	++YYCURSOR;
#line 38 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"
	{
	const char* number_begin = YYCURSOR;
	uint32_t num;
	while(*YYCURSOR != '"')
		++YYCURSOR;
	*YYCURSOR = 0;
	errno = 0;
	num = strtoul(number_begin, NULL, 10);
	if(errno != 0)
	{
		goto ERROR_RET;
	}
	self->sharedstring_begin_list = malloc(sizeof(char*) * num);
	if(self->sharedstring_begin_list == NULL)
	{
		goto ERROR_RET;
	}

	self->sharedstring_end_list = malloc(sizeof(char*) * num);
	if(self->sharedstring_end_list == NULL)
	{
		goto ERROR_RET;
	}

	while(*YYCURSOR != '>')
		++YYCURSOR;
	++YYCURSOR;
	YYMARKER = YYCURSOR;
	BEGIN(IN_SST);
	goto restart;
}
#line 270 "D:/GitHub/TLibC/source/gen/tlibc_xlsx_reader_sharedstring_l.c"
}
#line 87 "D:/GitHub/TLibC/source/protocol/tlibc_xlsx_reader_sharedstring_l.re"

ERROR_RET:
	if(self->sharedstring_begin_list != NULL)
	{
		free(self->sharedstring_begin_list);
	}

	if(self->sharedstring_end_list != NULL)
	{
		free(self->sharedstring_end_list);
	}
	return E_TLIBC_ERROR;
}


