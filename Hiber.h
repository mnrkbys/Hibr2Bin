/*++

Copyright (c) 2007 - 2017, Matthieu Suiche
Copyright (c) 2012 - 2014, MoonSols Limited
Copyright (c) 2015 - 2017, Comae Technologies FZE

Module Name:

    Hiber.h

Abstract:

    This module contains the internal structure definitions and APIs used by
    the Hibr2Bin.

Author:

    Matthieu Suiche (m) 1-April-2016

Revision History:

--*/

#ifndef __HIBER_DEF_H__
#define __HIBER_DEF_H__

#define HIBR_IMAGE_SIGNATURE          'RBIH'
#define HIBR_IMAGE_SIGNATURE_RESTORE  'RTSR'
#define HIBR_IMAGE_SIGNATURE_WAKE     'EKAW'
#define HIBR_IMAGE_SIGNATURE_BREAK    'PKRB'
#define HIBR_IMAGE_SIGNATURE_HORM     'MROH'

#define MAX_HIBER_PAGES (16)
#define PAGE_SIZE 0x1000
#define MAX_COMPRESSED_BLOCK (MAX_HIBER_PAGES * PAGE_SIZE)

//
// NT 5.0, NT 5.1, NT 6.0 x86
//
typedef struct _PO_MEMORY_RANGE_ARRAY_LINK32
{
    ULONG Next;
    ULONG NextTable;
    ULONG CheckSum;
    ULONG EntryCount;
} PO_MEMORY_RANGE_ARRAY_LINK32, *PPO_MEMORY_RANGE_ARRAY_LINK32;

typedef struct _PO_MEMORY_RANGE_ARRAY_RANGE32
{
    ULONG PageNo;
    ULONG StartPage;
    ULONG EndPage;
    ULONG CheckSum;
} PO_MEMORY_RANGE_ARRAY_RANGE32, *PPO_MEMORY_RANGE_ARRAY_RANGE32;

typedef struct _MEMORY_RANGE_ARRAY
{
    PO_MEMORY_RANGE_ARRAY_LINK32 Link;
    PO_MEMORY_RANGE_ARRAY_RANGE32 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_ARRAY32, *PPO_MEMORY_RANGE_ARRAY32;

//
// NT 5.2 x64
//
typedef struct _PO_MEMORY_RANGE_ARRAY_LINK64_NT52
{
    ULONGLONG Next;
    ULONGLONG NextTable;
    ULONG Checksum;
    ULONG EntryCount;
    ULONGLONG Reserved;
} PO_MEMORY_RANGE_ARRAY_LINK64_NT52, *PPO_MEMORY_RANGE_ARRAY_LINK64_NT52;

typedef struct _PO_MEMORY_RANGE_ARRAY_RANGE64_NT52
{
    ULONGLONG PageNo;
    ULONGLONG StartPage;
    ULONGLONG EndPage;
    ULONGLONG CheckSum;
} PO_MEMORY_RANGE_ARRAY_RANGE64_NT52, *PPO_MEMORY_RANGE_ARRAY_RANGE64_NT52;

typedef struct _MEMORY_RANGE_ARRAY64_NT52
{
    PO_MEMORY_RANGE_ARRAY_LINK64_NT52 Link;
    PO_MEMORY_RANGE_ARRAY_RANGE64_NT52 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_ARRAY64_NT52, *PPO_MEMORY_RANGE_ARRAY64_NT52;

//
// NT 6.0 x64
//
typedef struct _PO_MEMORY_RANGE_ARRAY_LINK64
{
    ULONGLONG Next;
    ULONGLONG NextTable;
    ULONG EntryCount;
    ULONG Padding;
} PO_MEMORY_RANGE_ARRAY_LINK64, *PPO_MEMORY_RANGE_ARRAY_LINK64;

typedef struct _PO_MEMORY_RANGE_ARRAY_RANGE64
{
    ULONGLONG StartPage;
    ULONGLONG EndPage;
} PO_MEMORY_RANGE_ARRAY_RANGE64, *PPO_MEMORY_RANGE_ARRAY_RANGE64;

typedef struct _MEMORY_RANGE_ARRAY64
{
    PO_MEMORY_RANGE_ARRAY_LINK64 Link;
    PO_MEMORY_RANGE_ARRAY_RANGE64 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_ARRAY64, *PPO_MEMORY_RANGE_ARRAY64;


//
// NT 6.1 x86
//
typedef struct _PO_MEMORY_RANGE_ARRAY_RANGE32_NT61 {
    ULONG StartPage;
    ULONG EndPage;
} PO_MEMORY_RANGE_ARRAY_RANGE32_NT61, *PPO_MEMORY_RANGE_ARRAY_RANGE32_NT61;

typedef struct _PO_MEMORY_RANGE_ARRAY_LINK32_NT61 {
    ULONG NextTable;
    ULONG EntryCount;
} PO_MEMORY_RANGE_ARRAY_LINK32_NT61, *PPO_MEMORY_RANGE_ARRAY_LINK32_NT61;

typedef struct _PO_MEMORY_RANGE_ARRAY32_NT61 {
    PO_MEMORY_RANGE_ARRAY_LINK32_NT61 Link;
    PO_MEMORY_RANGE_ARRAY_RANGE32_NT61 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_ARRAY32_NT61, *PPO_MEMORY_RANGE_ARRAY32_NT61;

//
// NT 6.1 x64
//
typedef struct _PO_MEMORY_RANGE_ARRAY_RANGE64_NT61 {
    ULONGLONG StartPage;
    ULONGLONG EndPage;
} PO_MEMORY_RANGE_ARRAY_RANGE64_NT61, *PPO_MEMORY_RANGE_ARRAY_RANGE64_NT61;

typedef struct _PO_MEMORY_RANGE_ARRAY_LINK64_NT61 {
    ULONGLONG NextTable;
    ULONG EntryCount;
    ULONG Padding;
} PO_MEMORY_RANGE_ARRAY_LINK64_NT61, *PPO_MEMORY_RANGE_ARRAY_LINK64_NT61;

typedef struct _PO_MEMORY_RANGE_ARRAY64_NT61 {
    PO_MEMORY_RANGE_ARRAY_LINK64_NT61 Link;
    PO_MEMORY_RANGE_ARRAY_RANGE64_NT61 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_ARRAY64_NT61, *PPO_MEMORY_RANGE_ARRAY64_NT61;


//
// Windows 8 32bits
//
typedef enum _HIBER_COMPRESS_METHOD
{
    XpressFast = 0,
    XpressMax = 1,
    XpressHuffFast = 2,
    XpressHuffMax = 3
} HIBER_COMPRESS_METHOD;

typedef struct _PO_MEMORY_RANGE32_NT62
{
    ULONG PageCount : 4;
    ULONG StartPage : 28;
} PO_MEMORY_RANGE32_NT62, *PPO_MEMORY_RANGE32_NT62;

typedef struct _PO_MEMORY_RANGE_TABLE32_NT62
{
    ULONG RangeCount : 8;
    ULONG CompressedSize : 22;
    ULONG CompressMethod : 2;
    PO_MEMORY_RANGE32_NT62 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_TABLE32_NT62, *PPO_MEMORY_RANGE_TABLE32_NT62;

#pragma pack(push) // push current alignment to stack
#pragma pack(4) // set alignment to 1 byte boundary
typedef struct _PO_MEMORY_RANGE64_NT62
{
    ULONG64 PageCount : 4;
    ULONG64 StartPage : 28;
} PO_MEMORY_RANGE64_NT62, *PPO_MEMORY_RANGE64_NT62;

typedef struct _PO_MEMORY_RANGE_TABLE64_NT62
{
    ULONG RangeCount : 8;
    ULONG CompressedSize : 22;
    ULONG CompressMethod : 2;
    PO_MEMORY_RANGE64_NT62 Range[ANYSIZE_ARRAY];
} PO_MEMORY_RANGE_TABLE64_NT62, *PPO_MEMORY_RANGE_TABLE64_NT62;
#pragma pack(pop)

#endif