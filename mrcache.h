
#pragma once
#include "common.h"
#include "hashtable.h"
#include "mrloop.h"

extern hashtable_t *mrq_ht;

enum cmds {
  GET = 1,
  SET,
  CMDS_END
};

struct settings {
  int port; 
  int max_memory; // mb
  int disk_size;  // mb
  uint32_t flags;
  mrLoop *loop;
};

#define ENABLE_COMPRESSION  settings.flags |= 0x1
#define COMPRESSION_ENABLED (settings.flags & 0x1)

extern struct settings settings;

typedef struct _conn my_conn_t;

typedef struct __attribute__((__packed__)) _item {
  uint16_t keysize;
  uint32_t size;
  char data[];
} item;

//static void flush();


//static void flush();

