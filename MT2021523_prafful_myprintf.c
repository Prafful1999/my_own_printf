                                        /*   MT2021523 PRAFFUL  RTOS ASSIGNMENT1     */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void sub_function_printk (const char *prafful, va_list args)
{
  
         int state = 0;
  
         int can_reset = 1;
  
         static char number_buffer[1000];
  
    while (*prafful)
    {
      
      if (state == 0)
	{
	  
         if (*prafful == '%')
	    {
	      
              state = 1;
	    
            }
	  
	  else
	    
	    {
	      
             putchar (*prafful);
	    
            }
	
       }
      
      else if (state == 1)
	{
	  
             switch (*prafful)
	    {
	    
                 case 'c':
	      {
		
                char ch = va_arg (args, int);
		
                putchar (ch);
		
                break;
	      
             }
	    
       case 's':
	      {
		
               const char *s = va_arg (args, const char *);
		
               while (*s)
		  {
		    
                    putchar (*s++);
		  
                  }
		
               break;
	      
               }
	    
 
      case 'd':
	      {
		
 
              sprintf (number_buffer, "%d", va_arg (args, int));
		
              fputs (number_buffer, stdout);
		
              break;
	      
              }
 	    
     case 'f':
	      
	      {
		
            sprintf (number_buffer, "%f", va_arg (args, double));
		
            fputs (number_buffer, stdout);
		
            break;
             	      
             }
	    
 
 
     case 'l':
	      
	      {
		int len = 4;
		
               for (int i = 0; i < len; i++)
		  
		  {
		    
                     if ((prafful[i] == 'l') && (prafful[i + 1] == 'd'))
		      
		      {
			
                           sprintf (number_buffer, "%ld", va_arg (args, long));
			
                           fputs (number_buffer, stdout);
			
                           i++;
	      
                      }
		    
		          else if ((prafful[i] == 'l') && (prafful[i + 1] == 'f'))
		      
		      {
			
                   sprintf (number_buffer, "%lf", va_arg (args, double));
			
                   fputs (number_buffer, stdout);
			
                   i++;
		      
 
                      }
		     else if ((prafful[i] == 'l') && (prafful[i + 1] == 'l') && (prafful[i + 2] == 'd'))
		      
		      {
			
                       sprintf (number_buffer, "%lld",va_arg (args, long long));
			
                       fputs (number_buffer, stdout);
			
                       i++;
		      
 
                     }
	  
                  } 
              } 
       } 
 
                  if (can_reset == 1)
	              {
	      
                      state = 0;
	    
 
                      }
	  
	             else
	                 {
	      
                          can_reset = 1;
	    
                         }
	
                      }
      
                   prafful++;
    
             }

        }


        void praffulprintf (const char *prafful, ...) 
         {
  
          va_list args;
  
          va_start (args, prafful);
  
          sub_function_printk (prafful, args);
  
          va_end (args);

         } 
 

        int main () 
         {
           int z = 30;
  
           float f1 = 22.23;
  
           double m = 75.75;
  
           long l = 87776;
  
           long long k = 7678687;
  
 
           praffulprintf ("Print a character : %c. Done! \n", 'P');
  
           praffulprintf ("Print a string: %s. Done! \n", "PRAFFUL RTOS");
  
           praffulprintf ("print a integer %d. Done! \n", z);
  
           praffulprintf ("print a floating point number %f. Done! \n", f1);
  
           praffulprintf ("print a double %lf. Done! \n", m);
  
           praffulprintf ("print a long  %ld. Done! \n", l);
  
           praffulprintf ("print a long long double %lld. Done! \n", k);
  
           return 0;

           }

