#include "tlibc/protocol/tlibc_binary_writer.h"
#include "tlibc/platform/tlibc_platform.h"
#include "tlibc/core/tlibc_util.h"
#include "tlibc/protocol/tlibc_abstract_writer.h"
#include "tlibc/core/tlibc_error_code.h"

#include <string.h>
#include <assert.h>


void tlibc_binary_writer_init(TLIBC_BINARY_WRITER *self, char *addr, uint32_t size)
{
	tlibc_abstract_writer_init(&self->super);

	self->super.write_char = tlibc_binary_write_char;
	self->super.write_double = tlibc_binary_write_double;
	self->super.write_int8_t = tlibc_binary_write_int8_t;
	self->super.write_int16_t = tlibc_binary_write_int16_t;
	self->super.write_int32_t = tlibc_binary_write_int32_t;
	self->super.write_int64_t = tlibc_binary_write_int64_t;
	self->super.write_uint8_t = tlibc_binary_write_uint8_t;
	self->super.write_uint16_t = tlibc_binary_write_uint16_t;
	self->super.write_uint32_t = tlibc_binary_write_uint32_t;
	self->super.write_uint64_t = tlibc_binary_write_uint64_t;
	self->super.write_string = tlibc_binary_write_string;

	self->addr = addr;
	self->size = size;
	self->offset = 0;
}

#define WRITER_CAPACITY(self) (self->size - self->offset)
#define WRITER_PTR(self) (self->addr + self->offset)

TLIBC_ERROR_CODE tlibc_binary_write_int8_t(TLIBC_ABSTRACT_WRITER *super, const int8_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(int8_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(int8_t*)WRITER_PTR(self) = *val;
	self->offset += sizeof(int8_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_int16_t(TLIBC_ABSTRACT_WRITER *super, const int16_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(int16_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(int16_t*)WRITER_PTR(self) = *val;
	tlibc_host16_to_little(*(int16_t*)WRITER_PTR(self));
	self->offset += sizeof(int16_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_int32_t(TLIBC_ABSTRACT_WRITER *super, const int32_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(int32_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(int32_t*)WRITER_PTR(self) = *val;
	tlibc_host32_to_little(*(int32_t*)WRITER_PTR(self));
	self->offset += sizeof(int32_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_int64_t(TLIBC_ABSTRACT_WRITER *super, const int64_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(int64_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(int64_t*)WRITER_PTR(self) = *val;
	tlibc_host64_to_little(*(int64_t*)WRITER_PTR(self));
	self->offset += sizeof(int64_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}


TLIBC_ERROR_CODE tlibc_binary_write_uint8_t(TLIBC_ABSTRACT_WRITER *super, const uint8_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(uint8_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(uint8_t*)WRITER_PTR(self) = *val;
	self->offset += sizeof(uint8_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_uint16_t(TLIBC_ABSTRACT_WRITER *super, const uint16_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(uint16_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(uint16_t*)WRITER_PTR(self) = *val;
	tlibc_host16_to_little(*(uint16_t*)WRITER_PTR(self));
	self->offset += sizeof(uint16_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_uint32_t(TLIBC_ABSTRACT_WRITER *super, const uint32_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(uint32_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(uint32_t*)WRITER_PTR(self) = *val;
	tlibc_host32_to_little(*(uint32_t*)WRITER_PTR(self));
	self->offset += sizeof(uint32_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_uint64_t(TLIBC_ABSTRACT_WRITER *super, const uint64_t *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(uint64_t))
	{
		goto not_enough_bytebuff_size;
	}
	*(uint64_t*)WRITER_PTR(self) = *val;
	tlibc_host64_to_little(*(uint64_t*)WRITER_PTR(self));
	self->offset += sizeof(uint64_t);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;

}

TLIBC_ERROR_CODE tlibc_binary_write_char(TLIBC_ABSTRACT_WRITER *super, const char *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(char))
	{
		goto not_enough_bytebuff_size;
	}
	*(char*)WRITER_PTR(self) = *val;
	self->offset += sizeof(char);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_double(TLIBC_ABSTRACT_WRITER *super, const double *val)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	if(WRITER_CAPACITY(self) < sizeof(double))
	{
		goto not_enough_bytebuff_size;
	}
	*(double*)WRITER_PTR(self) = *val;
	self->offset += sizeof(double);

	return E_TLIBC_NOERROR;
not_enough_bytebuff_size:
	return E_TLIBC_OUT_OF_MEMORY;
}

TLIBC_ERROR_CODE tlibc_binary_write_string(TLIBC_ABSTRACT_WRITER *super, const char* str)
{
	TLIBC_BINARY_WRITER *self = TLIBC_CONTAINER_OF(super, TLIBC_BINARY_WRITER, super);
	uint32_t str_len = 0;
	TLIBC_ERROR_CODE ret= E_TLIBC_NOERROR;

	for(; self->offset < self->size; )
	{
		char c = (self->addr[self->offset++] = str[str_len++]);

		if(c == 0)
		{
			goto done;
		}
	}

	ret = E_TLIBC_OUT_OF_MEMORY;
done:
	return ret;
}
