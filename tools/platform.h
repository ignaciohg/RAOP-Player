/*
 *  Squeeze2raop - LMS to Raop gateway
 *
 *  (c) Philippe, philippe_44@outlook.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __PLATFORM_H
#define __PLATFORM_H



#include <stdbool.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/poll.h>
#include <poll.h>
#include <dlfcn.h>
#include <pthread.h>
#include <errno.h>
#include <valgrind/memcheck.h>

typedef u_int8_t  u8_t;
typedef u_int16_t u16_t;
typedef u_int32_t u32_t;
typedef int16_t   s16_t;
typedef int32_t   s32_t;
typedef u_int64_t u64_t;
typedef int64_t   s64_t;

#define last_error() errno
#define ERROR_WOULDBLOCK EWOULDBLOCK

int SendARP(in_addr_t src, in_addr_t dst, u8_t mac[], u32_t *size);
#define fresize(f,s) ftruncate(fileno(f), s)
char *strlwr(char *str);
#define _random(x) random()
char *GetTempPath(u16_t size, char *path);
#define closesocket close


typedef u8_t  __u8;
typedef u16_t __u16;
typedef u32_t __u32;
typedef s16_t __s16;
typedef s32_t __s32;
typedef u64_t __u64;
typedef s64_t __s64;

typedef struct ntp_s {
	__u32 seconds;
	__u32 fraction;
} ntp_t;

u64_t timeval_to_ntp(struct timeval tv, struct ntp_s *ntp);
u64_t get_ntp(struct ntp_s *ntp);
u32_t gettime_ms(void);
u64_t gettime_ms64(void);

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif     // __PLATFORM
