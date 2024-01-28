#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int days_in_shamsi_month[] = {0, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};

char *shamsiMonths[] = {
        " ",
        "\033[1m               Farvardin              \033[0m\n",
        "\033[1m              Ordibehesht             \033[0m\n",
        "\033[1m                Khordad               \033[0m\n",
        "\033[1m                  Tir                 \033[0m\n",
        "\033[1m                 Mordad               \033[0m\n",
        "\033[1m               Shahrivar              \033[0m\n",
        "\033[1m                  Mehr                \033[0m\n",
        "\033[1m                  Aban                \033[0m\n",
        "\033[1m                  Azar                \033[0m\n",
        "\033[1m                  Dey                 \033[0m\n",
        "\033[1m                 Bahman               \033[0m\n",
        "\033[1m                 Esfand               \033[0m\n"
};

int weekdays(int year, int month)
{
    int daycode = (year * 365 + (year / 4) + 1) % 7;

    if (year >= 1206 && year <= 1218)
    {
        daycode += 2;
    }

    if (year >= 1208 && year <= 1218 && year != 1211 && year != 1215)
    {
        daycode = (daycode - 1) % 7;
    }

    if (year == 1219)
    {
        daycode = (daycode + 2) % 7;
    }

    if (year >= 1220 && year < 1300)
    {
        daycode = (daycode + 1) % 7;
    }

    for (int i = 1; i < month; i++)
    {
        daycode = (daycode + days_in_shamsi_month[i]) % 7;
    }

    return daycode;
}

int kabise(int year)
{
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
        return 1; 
    else
        return 0; 
}



void calendar(int year, int month , int daycode)
{
    int day;

    if (kabise(year) == 0)
    {
        days_in_shamsi_month[12] = 30;
    }
    else if (kabise(year) == 1)
    {
        days_in_shamsi_month[12] = 29;
    }

    printf("\n%s\n\n\033[3m sa    su    mo    tu    we    th    fr \033[0m\n\n",
           shamsiMonths[month]
    );

    for (day = 1; day <= daycode; day++)
    {
        printf("      ");
    }

    for (day = 1; day <= days_in_shamsi_month[month]; day++)
    {
        printf("%-6d", day);

    if ((day + daycode) % 7 == 0 || day == days_in_shamsi_month[month])
            printf("\n");
    }
    printf("----------------------------");
    if (month == 1)
    {
      printf(" \nnorooz\n");
      printf("rooz tanbiat");
    }
    else if (month == 2)
    {
      printf(" \nrooz meli khalij fars\n");
      printf("rooz kargar");
    }
     else if (month == 3)
    {
      printf(" \nrooz mohit zist\n");
      printf("rooz keshavarzi");
    }
     else if (month == 4)
    {
      printf(" \neaid fetr\n");
      printf("rooz ghalam");
    }
    
     else if (month == 5)
    {
      printf(" \nashora\n");
      printf("rooz ehda khon");
    }
     else if (month == 6)
    {
      printf(" \nrooz karmand\n");
      printf("rooz pezeshk");
    }
     else if (month == 7)
    {
      printf(" \nrooz salmand\n");
      printf("rooz jahangardi");
    }
     else if (month == 8)
    {
      printf(" \nrooz keyfiyat\n");
      printf("rooz farhang");
    }
     else if (month == 9)
    {
      printf(" \nrooz bimeh\n");
      printf("rooz daneshjoo");
    }
     else if (month == 10)
    {
      printf(" \nnew year\n");
      printf("rooz petroshimi");
    }
     else if (month == 11)
    {
      printf(" \nrooz gomrok\n");
      printf("rooz pedar");
    }
    
     else if (month == 12)
    {
      printf(" \nrooz derakht kari\n");
      printf("rooz meli shodan naft");
    }
    

    printf("\n--------------------------------\n");
    printf("enter 5 to jummp 5 monthe ! \n");
    printf("enter 0 to continu ! \n");
    int next ;
    scanf("%d", &next);
    if (next == 0 ){
      system("cls");
      main();

    }
    if( next == 5){
      system("cls");
      fivem(year , month);
    }
    //printf("\033[1myou will retern to menu in 10 seconds ...\033[0m\n");
    //sleep(10);
    
}

int fivem( int year , int month){
    int monthe;
    if ( month < 8) {
    monthe = month + 5 ; 
    }
    else if (month == 8)
    {
     monthe = 1 ;
    }
    else if (month == 9)
    {
     monthe = 2 ;
    }
    else if (month == 10)
    {
     monthe = 3 ;
    }
      else if (month == 11)
    {
      monthe = 4 ;
    }
      else if (month == 12)
    {
      monthe = 5 ;
    }

    
    int shamsiDayCode = weekdays(year, monthe);
    calendar(year ,monthe, shamsiDayCode);
    
    }


  void error(){
     printf("\033[0;31m");
     printf("\nInvalid option!\n\n");
     printf("\033[0m");
     sleep(4);
     system("cls");
}

  void case1(){
  
    int year , month ;
    printf("[0] => Menu\n\n");
    while (1)
    {
      printf("Enter the year : ");
      scanf("%d", &year);
      
      if (year == 0)
      {
        main();
        
      }
      if (year < 1206 || year > 1498)
      {
        error();
        case1();
        break;
      }
      
      
      printf("Enter the month : ");
      scanf("%d", &month);

      if ( month == 0 )
      {
        main();
        break;
      }

      while (month> 12 || month < 1)
      {
      system("cls");
      printf("Enter the month : ");
      scanf("%d", &month);
       if ( month == 0 )
      {
        main();
        break;
      }
     
      }
      
     // if (month < 1 || month > 12)
     // {
     //   error();
     //   case1();
     //   break;
     // }
      
      
      system("cls");
      int shamsiDayCode = weekdays(year, month);
      calendar(year ,month, shamsiDayCode);
    
    }
    
}

  void case2(){
      int y = 1402, m , d ;
      int year , month , day ;
      int yearr , monthr , dayr;
      int daynumber;
      printf("[0] => Menu\n\n");
      printf("Enter the current month : ") ;
      scanf("%d" ,&m);
      printf("Enter the current day : ") ;
      scanf("%d" ,&d);
      system("cls");
      printf("[0] => Menu\n\n");
      while (1)
      {
        printf("\nEnter the year : ");
        scanf("%d", &year);
        if (year == 0)
        {
          main();
          break;
        }
        if (year > 1402)
        {
          error();
          case2();
          break;
        }
        printf("Enter the month : ");
        scanf("%d", &month);
        if (month == 0)
        {
          main();
          break;
        }
        if (month < 1 || month > 12)
        {
          error();
          case2();
          break;
        }
        printf("Enter the day : ");
        scanf("%d", &day);
        if (day == 0)
        {
          main();
          break;
        }
        if (day > 31)
        {
          error();
          case2();
          break;

        }
        break;
  
      }
      system("cls");
      if (month < m)
      {
      yearr = y - year ;
      monthr = m - month -1 ;
      dayr = d + 30  - day ;
      printf("Your Age: %d years, %d months, %d days" , yearr , monthr , dayr);
      }
      else if ( month > m )
      {
      
      yearr = y - year -1 ;
      monthr = m + 12 - month -1;
      dayr = d + 30  - day ;
      printf("Your Age: %d years, %d months, %d days" , yearr , monthr , dayr);
  
      }
      else if (month == m  && d > day)
      {
        yearr = y - year ;
        monthr = 0 ;
        dayr = d - day;
        printf("Your Age: %d years, %d months, %d days" , yearr , monthr , dayr);
      }
      else if (month == m  && d < day)
      {
        yearr = y - year -1;
        monthr = 11 ;
        dayr = d + 30  - day ;
        printf("Your Age: %d years, %d months, %d days" , yearr , monthr , dayr);
      }
      daynumber = (yearr * 365 + dayr);
        if (monthr < 7){
          daynumber = daynumber + ((monthr - 1 ) * 31 );
          }
        if (monthr < 12){
          daynumber = (daynumber + (daynumber = daynumber +((monthr - 7) * 30 ) ));
          }  
          if (monthr == 12){
          daynumber = (daynumber + 336);
          }  
      
      printf("\n----------------------------\n you are %d days old " , daynumber/2 + 184);
     
      sleep(7);
      main();
    
  
      
  }

int case3miladi(){

    system("cls");
      printf("[0] => Menu\n\n");
    int year , month , day ;
    while (1)
    {
      printf("Enter the year : ");
      scanf("%d", &year);
      if (year == 0)
      {
        main();
        break;
      }
      printf("Enter the month : ");
      scanf("%d", &month);
      if (month == 0)
      {
        main();
        break;
      }
      printf("Enter the day : ");
      scanf("%d", &day);
      if (day == 0)
      {
        main();
        break;
      }
      break;
    
    }
    return 0;
}

int case3ghamari(){
    system("cls");
    printf("[0] => Menu\n\n");
    int year , month , day ;
    while (1)
    {
      printf("Enter the year : ");
      scanf("%d", &year);
      if (year == 0)
      {
        main();
        break;
      }
      printf("Enter the month : ");
      scanf("%d", &month);
      if (month == 0)
      {
        main();
        break;
      }
      printf("Enter the day : ");
      scanf("%d", &day);
      if (day == 0)
      {
        main();
        break;
      }
      break;
    
    }
    return 0;
}

int case31(){
    int option , n = 1;
    printf("[0] => Menu\n\n");
    while (1)
    {
    printf("[1] shamsi => miladi\n\n");
    printf("[2] shamsi => ghamari\n\n");
    printf("select option : ");
    scanf("%d", &option);
    if (option == 0)
      {
        main();
        break;
    
      }
        switch (option) {
       case 1:
           case3ghamari(n);
           break;
       case 2:
           case3ghamari(n);
           break;
           
       default:
           error();
           case31();
           break;
            
    }
    break;
    
    }
    return 0;
}

int main() {
     system("cls");
     int n = 1 ;
     int options ;
     printf("\n \t \x1b[47m Menu \x1b[0m\n");
     printf("------------------------\n");
     printf("\n[0] Quit\n");
     printf("\n[1] Calendar\n");
     printf("\n[2] Age\n");
     printf("\n[3] Conversion\n"); 
     printf("\n------------------------\n");    
     printf("\nselect option : ");
     scanf("%d", &options);
     system("cls");
     
     switch (options) {
        case 0:
            printf("Bye!\n\n");
            break;
        case 1:
            case1(n);
            break;
        case 2:
            case2(n);
            break;
        case 3:
            case31(n);
            break;
        default:
            error();
            main();
            
    }
     

return 0;
}