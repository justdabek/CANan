#include  <errno.h>
#include  "unistd.h" // STDOUT_FILENO, STDERR_FILENO
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "CAN.h"

extern HAL_UART_StateTypeDef huart5;

int _write(int file, char *data, int len)
{
   if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      errno = EBADF;
      return -1;
   }

   // arbitrary timeout 1000
   HAL_StatusTypeDef status =
      HAL_UART_Transmit(&huart5, (uint8_t*)data, len, 1000);

   // return # of bytes written - as best we can tell
   return (status == HAL_OK ? len : 0);
}

void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string,fmt,argp)) // build string
    {
        HAL_UART_Transmit(&huart5, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
    }
}

void my_printf(const char *fmt, ...) // custom printf() function
{
    va_list argp;
    va_start(argp, fmt);
    vprint(fmt, argp);
    va_end(argp);
}
