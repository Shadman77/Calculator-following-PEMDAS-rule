#define _WIN32_WINNT 0x0500
#include<gtk/gtk.h>
#include<stdio.h>
#include<string.h>
//#include <tchar.h>
#include <math.h>
#include<stdlib.h>
#include <windows.h>
GdkColor color1, color2, colorfg;
GtkWidget *main_window_window, *main_window_button, *dialog;
GtkWidget *main_window_1_button,*main_window_2_button,*main_window_3_button,*main_window_4_button,*main_window_5_button,*main_window_6_button,*main_window_7_button;
GtkWidget *main_window_8_button,*main_window_9_button,*main_window_0_button,*main_window_decimal_button;
GtkWidget *button_label, *drawingArea;
GtkWidget *main_window_plus_button,*main_window_minus_button,*main_window_multiply_button,*main_window_divide_button,*main_window_equal_button,*main_window_c_button,*main_window_delete_button;
GtkWidget *main_window_bracket_open_button,*main_window_bracket_close_button;
GtkWidget *main_window_text,*main_window_table;
char char_for_label[400];
char buffer[400];
char buffer_temp;//For the arrow buttons//
char scroll[18];
int str_lenght;//May be used later for scroll function on the label//
int switch1=0,arrow_switch;/*Arrow switch is the starting point of scroll from char_for_label*/
int counter1, counter2, counter3;//Used in scroll label//--//counter1 is a temp here...

/*Start of calculation functions*/
int i;
int j,a[100],l=1;
int t;
int c,d,e,te,dd;//te is for remebering the last a[] term number//
//d and dd are for beginning and ending of str1,str2 copy dd is for str2 ending only//
//e is the counter//
char dminus_to_plus[200];
char str11[200],str22[200],str33[200];
char str1[100], str2[100], str3[200], str4[200], str0[200], newstr[400];
//because dealing with floats...may need to increase the size of the strings//
char input1[400];
double x,y,z;
int mul_count;

int ccount,ccount2=0,swtch=0;
                char ttemp[400];
                int sign_rec;

void sign_change()
{
    swtch=0;
    if(input1[0]=='s')
                {
                    i=strlen(input1);
                    ccount2=0;
                    swtch=1;
                    for(ccount=1; ccount<i; ccount++)
                    {
                        ttemp[ccount2]=input1[ccount];
                        ccount2++;
                    }
                    ttemp[ccount2]='\0';
                    strcpy(input1,ttemp);
                    sign_rec++;
                }
                printf("\ntemp = %s",ttemp);
                printf("\nstrlen = %d",i);
                if(swtch==1)
                {
                    i=strlen(input1);
                    for(ccount=0; ccount<i; ccount++)
                    {
                        if(input1[ccount]=='s')
                            input1[ccount]='a';
                        else if(input1[ccount]=='a')
                            input1[ccount]='s';
                    }
                }
                printf("\n\n sign change = %s",input1);
}


void first_string()
{
    printf("\n\na[0] = %d\n\n",a[0]);
    if(t==1)//if begining
    {
        sprintf(str1,"");
        e=0;
        for(c=0; c<j; c++)
        {
            str1[e]=input1[c];
            e++;
        }
        str1[e]='\0';
    }
    else
    {
        sprintf(str1,"");
        e=0;
        t=t-1;
        d=a[t]+1;
        for(c=d; c<j; c++)
        {
            str1[e]=input1[c];
            e++;
        }
        str1[e]='\0';
        t++;
    }
    printf("\n\nfirst string = %s\n\n",str1);
}




void second_string()
{
    if(t==te)//if ending
    {
        sprintf(str2,"");
        e=0;
        d=a[t]+1;
        for(c=d; c<i; c++)
        {
            str2[e]=input1[c];
            e++;
        }
        str2[e]='\0';
    }
    else
    {
        sprintf(str2,"");
        e=0;
        d=a[t]+1;
        printf("\n\ninitial t = %d\n\n",t);
        t++;
        printf("\n\nfinal t = %d\n\n",t);
        dd=a[t]-1;
        for(c=d; c<=dd; c++)//because already subtracting 1 from a[t]//
        {
            str2[e]=input1[c];
            e++;
        }
        str2[e]='\0';
        t--;
    }
    printf("\n\nsecond string = %s\n\n",str2);
}



void third_string()
{
    sprintf(str3,"");
    e=0;
    int k;
    for(c=c; c<i; c++)
    {
        str3[e]=input1[c];
        e++;
    }
    str3[e]='\0';
    printf("\n\nstr3=%s\n",str3);
}
void multiply()
{
    x=atof(str1);
    y=atof(str2);
    z=x*y;
    printf("\nmul z = %f\n",z);
}

void adding()
{
    x=atof(str1);
    y=atof(str2);
    z=x+y;
    printf("\nx = %f, y = %f",x,y);
    printf("\nadd z = %f\n",z);
}

void dividing()
{
    x=atof(str1);
    y=atof(str2);
    z=x/y;
    printf("\nadd z = %f\n",z);
}

void substracting()
{
    x=atof(str1);
    y=atof(str2);
    z=x-y;
    printf("\nadd z = %f\n",z);
}




void zeroth_string()
{
    printf("\n\nt=%d\n",t);
    if(t==1)
    {
        sprintf(str0,"");
        printf("\n\nstr0=%s\n",str0);
    }
    else
    {
        sprintf(str0,"");
        //probably d and dd can be used here//
        d=a[t-1];
        for(e=0; e<=d; e++)
        {
            str0[e]=input1[e];
        }
        str0[e]='\0';
        printf("\n\nstr0=%s\n",str0);
    }
}


void new_string()
{
    sprintf(newstr,"");
    sprintf(newstr,"%s%f%s",str0,z,str3);
    printf("\n\nnewstr = %s",newstr);
}

int rd_dg = 0, rd_dg1 = 0;//For rd/dg button//

void CALC_DMAS()
{
    sign_rec=0;
    sign_change();
                 printf("\nswtch = %d",swtch);
                 printf("\nsign_rec = %d",sign_rec);



                while(1) //BEGINNING OF WHILE LOOP//
                {
                    printf("\n\nLOOP 1\n\n");
                    i = strlen(input1);
                    l=1;
                    mul_count=1;
                    printf("\n\nat loop start input1 = %s\n\n",input1);
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='a')||(input1[j]=='s')||(input1[j]=='m')||(input1[j]=='d'))
                        {
                            a[l]=j;
                            printf("\n%d\n",a[l]);
                            l++;
                        }
                    }
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='d')||(input1[j]=='m'))
                            mul_count++;
                    }
                    printf("\n\nValue of mul_count = %d\n\n",mul_count);
                    if(mul_count==1)
                        break;
                    te=l-1;
                    printf("\n\nte = %d",te);
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='d')||(input1[j]=='m'))
                        {
                            printf("\nj=%d",j);
                            for(t=1; t<=100; ++t)
                                if(a[t]==j)
                                {
                                    
                                    first_string();
                                    
                                    second_string();
                                    printf("\n\nat the end c = %d",c);
                                    printf("\n\nstr1 = %s",str1);
                                    printf("\n\nstr2 = %s",str2);
                                    third_string();
                                    if(input1[j]=='m')
                                        multiply();
                                    else if(input1[j]=='d')
                                        dividing();
                                    printf("\n\nbefore 0 str = %d\n\n",t);
                                    zeroth_string();
                                    new_string();
                                    strcpy(input1,newstr);
                                    printf("\n\ninput1 = %s\n\n",input1);//for debugging
                                    printf("\n===================================\n");//for debugging
                                    break;
                                }

                            break;//for doing one multiplication at a tym//
                        }
                    }
                    printf("\n\n at end of loop input1 = %s\n\n",input1);//for debugging
                }//CLOSING OF WHILE LOOP//


                while(1) //BEGINNING OF WHILE LOOP//
                {
                    sign_change();
                    printf("\n\nLOOP 2\n\n");
                    i = strlen(input1);
                    l=1;
                    mul_count=1;
                    printf("\n\nat loop start input1 = %s\n\n",input1);
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='a')||(input1[j]=='s')||(input1[j]=='m')||(input1[j]=='d'))
                        {
                            a[l]=j;
                            printf("\n%d\n",a[l]);
                            l++;
                        }
                    }
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='a')||(input1[j]=='s'))
                            mul_count++;
                    }
                    printf("\n\nValue of mul_count = %d\n\n",mul_count);
                    if(mul_count==1)
                        break;
                    te=l-1;
                    printf("\n\nte = %d",te);
                    for(j=0; j<i; ++j)
                    {
                        if((input1[j]=='a')||(input1[j]=='s'))
                        {
                            printf("\nj=%d",j);
                            for(t=1; t<=100; ++t)
                                if(a[t]==j)
                                {
                                    
                                    first_string();
                                    
                                    second_string();
                                    printf("\n\nat the end c = %d",c);
                                    printf("\n\nstr1 = %s",str1);
                                    printf("\n\nstr2 = %s",str2);
                                    third_string();
                                    if(input1[j]=='a')
                                        adding();
                                    else if(input1[j]=='s')
                                        substracting();
                                    printf("\n\nbefore 0 str = %d\n\n",t);
                                    zeroth_string();
                                    new_string();
                                    strcpy(input1,newstr);
                                    printf("\n\ninput1 = %s\n\n",input1);
                                    printf("\n===================================\n");
                                    break;
                                }

                            

                            break;//for doing one multiplication at a tym//
                        }
                    }
                    printf("\n\n at end of loop input1 = %s\n\n",input1);
                    //break; //breaking manually
                }//CLOSING OF WHILE LOOP//
}

//CLEAR BUTTON ESCAPE BUTTON//
void c_button()
{
    strcpy(char_for_label,"");
    strcpy(scroll,"");
    gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
    switch1 = 0;
}
//LABEL MANIPULATION//
void writing_on_label(GtkWidget *widget, gpointer data)
{


    if(switch1==0)
    {
        //SETTING SOME CONDITIONS ON THE INPUT//
    sprintf(buffer,"%s",data);
    if((char_for_label[strlen(char_for_label)-1]=='.')&&(buffer[0] == '.'))
        return 0;
    //sprintf(buffer,"%s",data);
    if((char_for_label[strlen(char_for_label)-1]=='(')&&(buffer[0] == ')'))
        return 0;
    if((char_for_label[strlen(char_for_label)-1]=='(')&&((buffer[0] == '*')||(buffer[0] == '/')))
        return 0;
    //if((buffer[0]=='*')||(buffer[0]=='/')){
    //       return 0;
    //}
    //if(((char_for_label[strlen(char_for_label-1)]=='+')||(char_for_label[strlen(char_for_label-1)]=='-')||(char_for_label[strlen(char_for_label-1)]=='*')||(char_for_label[strlen(char_for_label-1)]=='/'))&&
        if((buffer[0]=='+')||(buffer[0]=='-')||(buffer[0]=='*')||(buffer[0]=='/'))
    {
        if((char_for_label[strlen(char_for_label)-1]=='+')||(char_for_label[strlen(char_for_label)-1]=='-')||(char_for_label[strlen(char_for_label)-1]=='*')||(char_for_label[strlen(char_for_label)-1]=='/'))
           return 0;
    }

    if(buffer[0]=='.'){
    for(counter3=strlen(char_for_label)-1; counter3>=0;counter3--)
    {
        if(char_for_label[counter3]=='.')
            return 0;
        if((char_for_label[counter3]=='+')||(char_for_label[counter3]=='-')||(char_for_label[counter3]=='*')||(char_for_label[counter3]=='/')||(char_for_label[counter3]=='(')||(char_for_label[counter3]==')'))
            break;
    }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////change a sign if its in the last place///

        printf("testing %s\n",data);
        sprintf(char_for_label,"%s%s",char_for_label,data);//DATA IS WHERE THE SPECIFIC CHARECTER IS//
        str_lenght = strlen(char_for_label);
        if(str_lenght>18)
        {
            strcpy(scroll,"");
            counter2 = str_lenght-18;
            printf("counter2 %d\n",counter2);
            for(counter1=0; counter1<18; counter1++)
            {
                printf("counter1 %d\n",counter1);
                scroll[counter1]=char_for_label[counter1+counter2];
            }
            scroll[counter1]='\0';
            printf("%s\n",scroll);
        }
        else
        {
            strcpy(scroll,char_for_label);
        }
    }
    else
    {
        //FIRST ADDING THE CHARACTER IN THE REQUIRED PLACE//
        str_lenght = strlen(char_for_label);
        strcpy(buffer,"");
        for(counter3=0; counter3<str_lenght; counter3++)
        {
            if(char_for_label[counter3]=='|')
                break;
        }
        sprintf(buffer,"%s",data);
        buffer_temp = buffer[0];
        counter2=0;
        for(counter1=0; counter1<str_lenght+1; counter1++)
        {
            if(counter1!=counter3)
            {
                buffer[counter1] = char_for_label[counter2];
                counter2++;
            }
            else
            {
                //sprintf(buffer_temp,"%s",data);
                buffer[counter1] = buffer_temp;
                printf("\ndata = %s\n", data);
            }
        }
        buffer[counter1]='\0';
        strcpy(char_for_label,buffer);
        printf("\nchar_for_label = %s =========================\n",char_for_label);
        //NOW SHOWING ON LABEL//
        str_lenght = strlen(char_for_label);
        if(str_lenght>18)
        {
            if(scroll[0]=='|')
            {
                strcpy(scroll,"");
                arrow_switch = arrow_switch;
                counter2 = arrow_switch;
                for(counter1=0; counter1<18; counter1++)
                {
                    scroll[counter1] = char_for_label[counter2];
                    counter2++;
                }
                scroll[counter1]= '\0';
                gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
                return 0;
            }
            strcpy(scroll,"");
            arrow_switch = arrow_switch + 1;
            counter2 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter2];
                counter2++;
            }
            scroll[counter1]= '\0';
        }
        else
        {
            strcpy(scroll,char_for_label);
        }

    }

    gtk_label_set_text(GTK_LABEL(main_window_text),scroll);

}
void left_arrow()
{
    if(strlen(char_for_label)==0)
        return 0;
    if(strlen(char_for_label)==1)
        return 0;
    //FOR WHEN AT THE RIGHT MOST//
    /*if(char_for_label[1]=='|')
        return 0;*/
    if(char_for_label[0]=='|')
        return 0;
    //FOR THE BEGINNING//
    if(switch1==0)
    {
        printf("before %s\n",char_for_label);
        strcpy(buffer,char_for_label);
        sprintf(char_for_label,"%s|",buffer);
        printf("after %s\n",char_for_label);
    }
    if(switch1>0)
    {
        printf("before %s\n",char_for_label);
        counter1=strlen(char_for_label)-switch1;
        buffer_temp = char_for_label[counter1-1];
        char_for_label[counter1-1] = char_for_label[counter1];
        char_for_label[counter1] = buffer_temp;
        printf("after %s\n",char_for_label);
    }
    //////////////////////////////////////////////////////////////
    switch1++;//DO NOT CALCULATE WITH 0...0 MEANS NON EXISTANCE//
    //CALCULATING POSITION OF | ON LABEL//
    //for(counter3 = 0; counter3 < 18; counter3++)
    //{
    //    if(scroll[counter3]=='|')
    //break;
    // }
    //SHOWING ON LABEL//

    str_lenght = strlen(char_for_label);
    //FOR SHORT STRING LESS THAN EQUAL TO 18(INCLUDING |)//
    if(str_lenght<=18)
    {
        strcpy(scroll,char_for_label);
    }
    //if((str_lenght>18)&&(counter3==1)
    if(str_lenght>18)
    {

        if(switch1==1)
        {
            strcpy(scroll,"");
            counter3 = strlen(char_for_label) - 18;
            arrow_switch = counter3;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
            gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
            return 0;
        }
        printf("\nscroll = %s\n",scroll);
        for(counter3=0; counter3<18; counter3++)
        {
            if(scroll[counter3]=='|')
            {
                //printf("\n%d",counter3);
                break;
            }
        }
        printf("\ncounter3 = %d",counter3);
        if(counter3!=1)
        {
            strcpy(scroll,"");
            counter3 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
        }
        if(counter3 == 1)
        {
            strcpy(scroll,"");
            arrow_switch = arrow_switch - 1;
            if(char_for_label[0]=='|')///////////////////
                arrow_switch++;/////////////////////
            counter3 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
        }


    //SHOWING RESULT ON LABEL//
    ///////////////////////////////////////////////////////////
    gtk_label_set_text(GTK_LABEL(main_window_text),scroll);//THIS IS THE LAST PART//
    /////////////////////////////////////////////////////////
}
//RIGHT ARROW//
void right_arrow()
{
    if(switch1==0)
        return 0;
    //FOR THE BEGINNING//
    if(switch1==1)
    {
        printf("before %s\n",char_for_label);
        strcpy(buffer,"");
        str_lenght = strlen(char_for_label)-1;
        for(counter1=0; counter1<str_lenght; counter1++)
        {
            buffer[counter1]=char_for_label[counter1];
        }
        buffer[counter1]='\0';
        strcpy(char_for_label,buffer);
        printf("after %s\n",char_for_label);
    }
    if(switch1>1)
    {
        printf("before %s\n",char_for_label);
        counter1=strlen(char_for_label)-switch1;
        buffer_temp = char_for_label[counter1+1];
        char_for_label[counter1+1] = char_for_label[counter1];
        char_for_label[counter1] = buffer_temp;
        printf("after %s\n",char_for_label);
    }
    switch1--;
    /////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    //SHOWING ON LABEL//
    str_lenght = strlen(char_for_label);
    //FOR SHORT STRING LESS THAN EQUAL TO 18(INCLUDING |)//
    if(str_lenght<=18)
    {
        strcpy(scroll,char_for_label);
    }
    //////////////////////////////////////////////////////////////////////////////////////
    str_lenght = strlen(char_for_label);
    if(str_lenght>18)
    {
        if(switch1!=0)
        {
            //CALCULATING POSITION OF | ON LABEL//+++++++++++++++++++++++++++++++++
            for(counter3 = 0; counter3 < 18; counter3++)
            {
                if(scroll[counter3]=='|')
                    break;
            }
            printf("\ncounter3 = %d\n",counter3);
            ///////////////////////////////////////////////
            if(counter3!=17)
            {
                printf("\nACTIVATED1\n");
                strcpy(scroll,"");
                counter3 = arrow_switch;
                for(counter1=0; counter1<18; counter1++)
                {
                    scroll[counter1] = char_for_label[counter3];
                    counter3++;
                }
                scroll[counter1]= '\0';
            }
            //printf("\ncounter3 = %d\n",counter3);
            ///////////////////////////////////////////////////////
            //if(counter1==17)
            else
            {
                printf("\nACTIVATED2\n");
                strcpy(scroll,"");
                arrow_switch = arrow_switch + 1;
                counter3 = arrow_switch;
                for(counter1=0; counter1<18; counter1++)
                {
                    scroll[counter1] = char_for_label[counter3];
                    counter3++;
                }
                scroll[counter1]= '\0';
            }//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        }
        else
        {
            printf("\n+++++activated++++++\n");
            strcpy(scroll,"");
            arrow_switch = strlen(char_for_label)-18;
            counter3 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
        }

    }


    //SHOWING RESULT ON LABEL//
    ///////////////////////////////////////////////////////////
    gtk_label_set_text(GTK_LABEL(main_window_text),scroll);//THIS IS THE LAST PART//
    /////////////////////////////////////////////////////////
}
//DELETE BUTTON//
void delete_button()
{
    printf("before = %s\n",char_for_label);
    if(switch1==0)
    {
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        str_lenght = strlen(char_for_label);
        for(counter1=0; counter1<str_lenght-1; counter1++)
        {
            buffer[counter1] = char_for_label[counter1];
        }
        buffer[counter1] = '\0';
        strcpy(char_for_label,buffer);
        //////WRITING ON LABEL//////////
        str_lenght = strlen(char_for_label);
        if(str_lenght>18)
        {
            printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            strcpy(scroll,"");
            counter2 = str_lenght-18;
            printf("counter2 %d\n",counter2);
            for(counter1=0; counter1<18; counter1++)
            {
                printf("counter1 %d\n",counter1);
                scroll[counter1]=char_for_label[counter2];
                counter2++;
            }
            scroll[counter1]='\0';
            printf("%s\n",scroll);
            //SHOWING RESULT ON LABEL//
            ///////////////////////////////////////////////////////////
            gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
            return 0;
        }
        else
        {
            strcpy(scroll,"");
            strcpy(scroll,char_for_label);
            //SHOWING RESULT ON LABEL//
            ///////////////////////////////////////////////////////////
            gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
            return 0;
        }//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    }
    else
    {
        //FIRSTLY DELETING THE SPECIFIC CHARACTER//
        str_lenght = strlen(char_for_label);
        strcpy(buffer,"");
        for(counter3=0; counter3<str_lenght; counter3++)
        {
            if(char_for_label[counter3]=='|')
                break;
        }
        counter2=0;
        for(counter1=0; counter1<str_lenght; counter1++)
        {
            if(counter1!=counter3-1)
            {
                buffer[counter2] = char_for_label[counter1];
                counter2++;
            }
        }
        buffer[counter2]='\0';
        strcpy(char_for_label,buffer);

    }

    printf("after =  %s\n",char_for_label);
    if(counter3==0)
    {
        printf("reached the end\n");
        return 0;
    }
    
    str_lenght = strlen(char_for_label);
    printf("strlenght\n = %d",str_lenght);
    if(str_lenght<18)
    {
        strcpy(scroll,char_for_label);
    }
    else
    {
        strcpy(scroll,"");
        if(arrow_switch!=0)
        {
            arrow_switch = arrow_switch - 1;
            counter3 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
        }
        else
        {
            counter3 = arrow_switch;
            for(counter1=0; counter1<18; counter1++)
            {
                scroll[counter1] = char_for_label[counter3];
                counter3++;
            }
            scroll[counter1]= '\0';
        }
    }

    //SHOWING RESULT ON LABEL//
    ///////////////////////////////////////////////////////////
    gtk_label_set_text(GTK_LABEL(main_window_text),scroll);
}
////////////////////////////////////////////////////////////////////////////////
//START OF CALCULATION CALLBACK FUNCTION//
////////////////////////////////////////////
void calculation_button()
{

    if(switch1!=0)
        return 0;
    if((char_for_label[strlen(char_for_label)-1]=='+')||(char_for_label[strlen(char_for_label)-1]=='-')||(char_for_label[strlen(char_for_label)-1]=='*')||(char_for_label[strlen(char_for_label)-1]=='/')){
            gtk_label_set_text(GTK_LABEL(main_window_text),"Syntax Error");
           return 0;
    }
    if((char_for_label[0]=='*')||(char_for_label[0]=='/')){
            gtk_label_set_text(GTK_LABEL(main_window_text),"Syntax Error");
           return 0;
    }
    ///22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222///
                //GetWindowText(hInput1, input1, 400);
                strcpy(input1,char_for_label);
                //printf("\n\n%s\n\n",input1);
                //IF FIRST MINUS THEN CONVERT TO PLUS THEN CALCULATE TILL THE END AND THEN MULTIPLY BY -1//
                int count_syntax,count_peren;
                int addresss[100];
                swtch=0;
                printf("\n\ninput1 = %s",input1);
                 i=strlen(input1);

                 for(count_syntax=0;count_syntax<i;count_syntax++)
                 {
                     if(((input1[count_syntax]=='+')||(input1[count_syntax]=='-')||(input1[count_syntax]=='*')||(input1[count_syntax]=='/'))
                       && ((input1[count_syntax+1]=='+')||(input1[count_syntax+1]=='-')||(input1[count_syntax+1]=='*')||(input1[count_syntax+1]=='/')))
                     {
                         printf("\n=================================\nsyntax error\n========================================================================\n\n");
                        //sprintf(str4,"Syntax Error");
                        //SetWindowText(hInput3, str4);
                        //DIALOG BOX//
                        dialog = gtk_message_dialog_new (GTK_WINDOW (main_window_window), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Syntax Error!");
    gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
    ///////////////////////////////////////////////////////////
                        return 0;

                     }



                 }


                 int cter1,cter2=0;

                 for(cter1=0;cter1<i;cter1++)
                 {
                     if(input1[cter1]=='(')
                            cter2++;
                     if(input1[cter1]==')')
                            cter2--;
                 }


                 if(cter2!=0)
                 {
                     //sprintf(str4,"Syntax Error");
                        //SetWindowText(hInput3, str4);
                        //DIALOG BOX//
                        dialog = gtk_message_dialog_new (GTK_WINDOW (main_window_window), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Syntax Error!");
    gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
    ///////////////////////////////////////////////////////////
                        return 0;
                 }

                 for(count_syntax=0;count_syntax<i;count_syntax++)
                 {
                     if(input1[count_syntax]=='+')
                        input1[count_syntax]='a';
                     if(input1[count_syntax]=='-')
                        input1[count_syntax]='s';
                     if(input1[count_syntax]=='*')
                        input1[count_syntax]='m';
                     if(input1[count_syntax]=='/')
                        input1[count_syntax]='d';
                 }

                 printf("\nNew input1 is %s",input1);
                 //return 0; //for testing purpose//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
                 int bl;
                 while(1){
                        bl=0;
                 i=strlen(input1);
                 for(count_peren=0;count_peren<i;count_peren++)
                 {
                     if(input1[count_peren]=='('){
                            j=count_peren;
                 bl++;}
                 }
                 if(bl==0)
                    break;
                 printf("\ncount_peren = %d",count_peren);

                 //USING STR1 AND STR2 AND STR3//
                 //IN THE END JUST USE SPRINTF//



                 //========STR1==========//
                 strcpy(str11,"");
                 for(e=0;e<j;e++)
                 {
                     str11[e]=input1[e];
                 }
                 str11[e]='\0';
                 printf("\n str1 = %s",str11);

                 printf("\nstrlen = %d",i);
                 //========STR1==========//


                 printf("\n j = %d", j);

                 //=======STR2==========//
                 strcpy(str22,"");
                 j++;
                 e=0;
                 while(input1[j]!=')')
                 {
                     str22[e]=input1[j];
                     e++;
                     j++;
                 }
                 str22[e]='\0';

                 printf("\n str2 = %s",str22);
                 //=====STR2=====//

                 printf("\n j = %d",j);

                 //========STR3========//
                 strcpy(str33,"");
                 j++;
                 e=0;
                 while(j!=i)
                 {
                     str33[e]=input1[j];
                     e++;
                     j++;
                 }
                 str33[e]='\0';

                 printf("\n str3 = %s",str33);
                 //========STR3========//


                 //======calculate========//
                 strcpy(input1,str22);

                 CALC_DMAS();
                 if(sign_rec%2!=0)
                    sprintf(str4,"-%s",input1);
                else
                    sprintf(str4,"%s",input1);
//---------------------------------------------------------------------------------------//
                    strcpy(dminus_to_plus,"");

                    i=strlen(str4);
                    e=0;
                    if((str4[0]=='-')&&(str4[1]=='-'))
                       {
                           for(count_syntax=2;count_syntax<i;count_syntax++)
                            {
                                dminus_to_plus[e]=str4[count_syntax];
                                e++;
                            }
                            dminus_to_plus[e]='\0';
                            e=0;
                            strcpy(str4,dminus_to_plus);
                       }

                       printf("\ndminus_to_plus = %s",dminus_to_plus);

//---------------------------------------------------------------------------------------//


                printf("\n\n Ans str4 = %s",str4);

                //======calculate========//

                //========Remake========//
                sprintf(input1,"%s%s%s",str11,str4,str33);
                printf("\nRemade input1 = %s",input1);
                 }
                 //return 0; //for testing//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
                 //return 0;//for testing purpose only//


                 CALC_DMAS();



                printf("\n\nAT THE END sign_rec = %d",sign_rec);
                if(sign_rec%2!=0)
                    sprintf(str4,"-%s",input1);
                else
                    sprintf(str4,"%s",input1);

                    //---------------------------------------------------------------------------------------//
                    strcpy(dminus_to_plus,"");

                    i=strlen(str4);
                    e=0;
                    if((str4[0]=='-')&&(str4[1]=='-'))
                       {
                           for(count_syntax=2;count_syntax<i;count_syntax++)
                            {
                                dminus_to_plus[e]=str4[count_syntax];
                                e++;
                            }
                            dminus_to_plus[e]='\0';
                            e=0;
                            strcpy(str4,dminus_to_plus);
                       }

                       printf("\ndminus_to_plus = %s",dminus_to_plus);

//---------------------------------------------------------------------------------------//

                printf("\n\n Ans str4 = %s",str4);
                char oouutput[100];
                double zz = atof(str4);
                sprintf(oouutput,"%.3f",zz);
                        //SetWindowText(hInput3, oouutput);
                        gtk_label_set_text(GTK_LABEL(main_window_text),oouutput);


///222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222///
}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
gint key_press_cb(GtkWidget *widget, GdkEventKey *kevent, gpointer data)//this is the format...so best to leave untouched!!//
{
    //GtkWidget *btn = (GtkWidget *)data;//umm this is not needed

    if(kevent->type == GDK_KEY_PRESS)
    {
        g_message("%d, %c;", kevent->keyval, kevent->keyval);
        gtk_window_set_focus(main_window_window,NULL);//VVIMP...NULL MEANS NO WIDGET HAS FOCUS!!//

    }

    // void g_signal_emit_by_name(GObject *object, const gchar *name, ... );
    // g_signal_emit_by_name(G_OBJECT(btn), "clicked", NULL);
    if((kevent->keyval==48)||(kevent->keyval==65456))//using "0" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_0_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==49)||(kevent->keyval==65457))//using "1" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_1_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==50)||(kevent->keyval==65458))//using "2" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_2_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==51)||(kevent->keyval==65459))//using "3" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_3_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==52)||(kevent->keyval==65460))//using "4" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_4_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==53)||(kevent->keyval==65461))//using "5" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_5_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==54)||(kevent->keyval==65462))//using "6" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_6_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==55)||(kevent->keyval==65463))//using "7" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_7_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==56)||(kevent->keyval==65464))//using "8" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_8_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==57)||(kevent->keyval==65465))//using "9" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_9_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==43)||(kevent->keyval==65451))//using "+" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_plus_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==45)||(kevent->keyval==65453))//using "-" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_minus_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==42)||(kevent->keyval==65450))//using "*" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_multiply_button), "activate", NULL);
        return TRUE;
    }
    if((kevent->keyval==47)||(kevent->keyval==65455))//using "/" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_divide_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==65293)//using "enter" as the trigger//FOR WINDOWS!!
    //if((kevent->keyval==65293)||(kevent->keyval==65421))
    {
        g_signal_emit_by_name(G_OBJECT(main_window_equal_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==46)//using "." as the trigger//FOR WINDOWS!!
    //if((kevent->keyval == 46)||(kevent->keyval==65454))
    {
        g_signal_emit_by_name(G_OBJECT(main_window_decimal_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==65307)//using "esc" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_c_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==65288)//using "backspace" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_delete_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==40)//using "(" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_bracket_open_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==41)//using ")" as the trigger//
    {
        g_signal_emit_by_name(G_OBJECT(main_window_bracket_close_button), "activate", NULL);
        return TRUE;
    }
    if(kevent->keyval==65361)//using "LEFT ARROW" as the trigger//
    {
        left_arrow();
        return TRUE;
    }
    if(kevent->keyval==65363)//using "RIGHT ARROW" as the trigger//
    {
        right_arrow();
        return TRUE;
    }



    return TRUE;//goes on to do other works//
}
int main(int argc, char *argv[])
{
    //hiding the console//
    HWND hWnd = GetConsoleWindow();
    //ShowWindow( hWnd, SW_MINIMIZE );  //won't hide the window without SW_MINIMIZE
    ShowWindow( hWnd, SW_HIDE );
    gtk_init(&argc, &argv);
    //GDK COLOR FOR BUTTON//
    gdk_color_parse( "#343d46", &color1 );
    gdk_color_parse( "#c0c5ce", &color2 );
    gdk_color_parse( "#ffffff", &colorfg );
    //gdk_color_parse( "#0080FF", &color );
    //CREATING WINDOW//
    main_window_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window_window),"Calculator(Shadman)");
    gtk_window_set_position(GTK_WINDOW(main_window_window),GTK_WIN_POS_CENTER);
    //gtk_window_set_decorated (GTK_WINDOW (main_window_window), FALSE);
    gtk_window_set_resizable(GTK_WINDOW(main_window_window),FALSE);
    //gtk_container_set_border_width(main_window_window,10);
    //gtk_window_set_accept_focus(main_window_window,NULL);//VVIMP...NULL MEANS NO WIDGET HAS FOCUS!!//
    g_signal_connect(G_OBJECT(main_window_window), "key_press_event", G_CALLBACK(key_press_cb), NULL);
    //CREATING TABLE//
    main_window_table = gtk_table_new(4,6,FALSE);
    gtk_container_add(GTK_CONTAINER(main_window_window),main_window_table);
    gtk_widget_show(main_window_table);
    //DRAWING RECTANGLE//
    /*drawingArea = gtk_entry_new();
    gtk_widget_set_size_request(drawingArea,290,50);
    gtk_table_attach(GTK_TABLE(main_window_table),drawingArea,0,4,0,1,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_modify_bg( GTK_WIDGET(drawingArea), GTK_STATE_ACTIVE, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(drawingArea), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(drawingArea), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_show(drawingArea);*/
    //CREATING LABEL//
    main_window_text = gtk_label_new("");
    gtk_widget_set_size_request(main_window_text,290,50);//FOR WINDOWS!!//
    //gtk_widget_set_size_request(main_window_text,260,50);//FOR LINUX!!/
    //gtk_entry_set_alignment(main_window_text,1);
    gtk_misc_set_alignment(main_window_text,1,0.5);
    PangoFontDescription *fontDesc = pango_font_description_from_string( "monospace 20" );
    gtk_widget_modify_font (main_window_text,fontDesc);
    //pango_font_descriptions_free(fontDesc,1);
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_text,0,4,0,1,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    //gtk_container_add(GTK_CONTAINER(drawingArea),main_window_text);
    gtk_widget_show(main_window_text);
    //CREATING ESCAPE"C" BUTTON//
    main_window_c_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_c_button,0,1,1,2,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_c_button,30,50);
    g_signal_connect(G_OBJECT(main_window_c_button), "key_press_event", G_CALLBACK(key_press_cb), NULL);
    g_signal_connect(main_window_c_button,"clicked",G_CALLBACK(c_button),NULL);
    gtk_widget_show(main_window_c_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("C");
    gtk_container_add(GTK_CONTAINER(main_window_c_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_c_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_c_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_c_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING DELETE BUTTON//
    main_window_delete_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_delete_button,1,2,1,2,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_delete_button,30,50);
    g_signal_connect(G_OBJECT(main_window_delete_button), "key_press_event", G_CALLBACK(key_press_cb), NULL);
    g_signal_connect(main_window_delete_button,"clicked",G_CALLBACK(delete_button),NULL);
    gtk_widget_show(main_window_delete_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("<-");
    gtk_container_add(GTK_CONTAINER(main_window_delete_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_delete_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_delete_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_delete_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING DIVIDE BUTTON//
    main_window_divide_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_divide_button,2,3,1,2,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_divide_button,30,50);
    g_signal_connect(G_OBJECT(main_window_divide_button), "key_press_event", G_CALLBACK(key_press_cb), "/");
    g_signal_connect(main_window_divide_button,"clicked",G_CALLBACK(writing_on_label),"/");
    gtk_widget_show(main_window_divide_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("/");
    gtk_container_add(GTK_CONTAINER(main_window_divide_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_divide_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_divide_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_divide_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING MULTIPLY BUTTON//
    main_window_multiply_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_multiply_button,3,4,1,2,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_multiply_button,30,50);
    g_signal_connect(G_OBJECT(main_window_multiply_button), "key_press_event", G_CALLBACK(key_press_cb), "*");
    g_signal_connect(main_window_multiply_button,"clicked",G_CALLBACK(writing_on_label),"*");
    gtk_widget_show(main_window_multiply_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("×");
    gtk_container_add(GTK_CONTAINER(main_window_multiply_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_multiply_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_multiply_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_multiply_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING MINUS BUTTON//
    main_window_minus_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_minus_button,3,4,3,4,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_minus_button,30,50);
    g_signal_connect(G_OBJECT(main_window_minus_button), "key_press_event", G_CALLBACK(key_press_cb), "-");
    g_signal_connect(main_window_minus_button,"clicked",G_CALLBACK(writing_on_label),"-");
    gtk_widget_show(main_window_minus_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("-");
    gtk_container_add(GTK_CONTAINER(main_window_minus_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_minus_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_minus_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_minus_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 7 BUTTON//
    main_window_7_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_7_button,0,1,2,3,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_7_button,30,50);
    g_signal_connect(G_OBJECT(main_window_7_button), "key_press_event", G_CALLBACK(key_press_cb), "7");
    g_signal_connect(main_window_7_button,"clicked",G_CALLBACK(writing_on_label),"7");
    gtk_widget_show(main_window_7_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("7");
    gtk_container_add(GTK_CONTAINER(main_window_7_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_7_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_7_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_7_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 8 BUTTON//
    main_window_8_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_8_button,1,2,2,3,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_8_button,30,50);
    g_signal_connect(G_OBJECT(main_window_8_button), "key_press_event", G_CALLBACK(key_press_cb), "8");
    g_signal_connect(main_window_8_button,"clicked",G_CALLBACK(writing_on_label),"8");
    gtk_widget_show(main_window_8_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("8");
    gtk_container_add(GTK_CONTAINER(main_window_8_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_8_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_8_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_8_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 9 BUTTON//
    main_window_9_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_9_button,2,3,2,3,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_9_button,30,50);
    g_signal_connect(G_OBJECT(main_window_9_button), "key_press_event", G_CALLBACK(key_press_cb), "9");
    g_signal_connect(main_window_9_button,"clicked",G_CALLBACK(writing_on_label),"9");
    gtk_widget_show(main_window_9_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("9");
    gtk_container_add(GTK_CONTAINER(main_window_9_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_9_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_9_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_9_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING PLUS BUTTON//
    main_window_plus_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_plus_button,3,4,2,3,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_plus_button,30,50);
    g_signal_connect(G_OBJECT(main_window_plus_button), "key_press_event", G_CALLBACK(key_press_cb), "+");
    g_signal_connect(main_window_plus_button,"clicked",G_CALLBACK(writing_on_label),"+");
    gtk_widget_show(main_window_plus_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("+");
    gtk_container_add(GTK_CONTAINER(main_window_plus_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_plus_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_plus_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_plus_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 4 BUTTON//
    main_window_4_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_4_button,0,1,3,4,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_4_button,30,50);
    g_signal_connect(G_OBJECT(main_window_4_button), "key_press_event", G_CALLBACK(key_press_cb), "4");
    g_signal_connect(main_window_4_button,"clicked",G_CALLBACK(writing_on_label),"4");
    gtk_widget_show(main_window_4_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("4");
    gtk_container_add(GTK_CONTAINER(main_window_4_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_4_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_4_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_4_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 5 BUTTON//
    main_window_5_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_5_button,1,2,3,4,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_5_button,30,50);
    g_signal_connect(G_OBJECT(main_window_5_button), "key_press_event", G_CALLBACK(key_press_cb), "5");
    g_signal_connect(main_window_5_button,"clicked",G_CALLBACK(writing_on_label),"5");
    gtk_widget_show(main_window_5_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("5");
    gtk_container_add(GTK_CONTAINER(main_window_5_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_5_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_5_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_5_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 6 BUTTON//
    main_window_6_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_6_button,2,3,3,4,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_6_button,30,50);
    g_signal_connect(G_OBJECT(main_window_6_button), "key_press_event", G_CALLBACK(key_press_cb), "6");
    g_signal_connect(main_window_6_button,"clicked",G_CALLBACK(writing_on_label),"6");
    gtk_widget_show(main_window_6_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("6");
    gtk_container_add(GTK_CONTAINER(main_window_6_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_6_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_6_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_6_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 1 BUTTON//
    main_window_1_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_1_button,0,1,4,5,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_1_button,30,50);
    g_signal_connect(G_OBJECT(main_window_1_button), "key_press_event", G_CALLBACK(key_press_cb), "1");
    g_signal_connect(main_window_1_button,"clicked",G_CALLBACK(writing_on_label),"1");
    gtk_widget_show(main_window_1_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("1");
    gtk_container_add(GTK_CONTAINER(main_window_1_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_1_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_1_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_1_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 2 BUTTON//
    main_window_2_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_2_button,1,2,4,5,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_2_button,30,50);
    g_signal_connect(G_OBJECT(main_window_2_button), "key_press_event", G_CALLBACK(key_press_cb), "2");
    g_signal_connect(main_window_2_button,"clicked",G_CALLBACK(writing_on_label),"2");
    gtk_widget_show(main_window_2_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("2");
    gtk_container_add(GTK_CONTAINER(main_window_2_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_2_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_2_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_2_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 3 BUTTON//
    main_window_3_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_3_button,2,3,4,5,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_3_button,30,50);
    g_signal_connect(G_OBJECT(main_window_3_button), "key_press_event", G_CALLBACK(key_press_cb), "3");
    g_signal_connect(main_window_3_button,"clicked",G_CALLBACK(writing_on_label),"3");
    gtk_widget_show(main_window_3_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("3");
    gtk_container_add(GTK_CONTAINER(main_window_3_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_3_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_3_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_3_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING EQUAL BUTTON//
    main_window_equal_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_equal_button,3,4,4,5,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_equal_button,30,50);
    g_signal_connect(G_OBJECT(main_window_equal_button), "key_press_event", G_CALLBACK(key_press_cb), NULL);
    g_signal_connect(main_window_equal_button,"clicked",G_CALLBACK(calculation_button),NULL);
    gtk_widget_show(main_window_equal_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("=");
    gtk_container_add(GTK_CONTAINER(main_window_equal_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_equal_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_equal_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_equal_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING BRACKET OPEN BUTTON//
    main_window_bracket_open_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_bracket_open_button,0,1,5,6,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_bracket_open_button,30,50);
    g_signal_connect(G_OBJECT(main_window_bracket_open_button), "key_press_event", G_CALLBACK(key_press_cb), "(");
    g_signal_connect(main_window_bracket_open_button,"clicked",G_CALLBACK(writing_on_label),"(");
    gtk_widget_show(main_window_bracket_open_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("(");
    gtk_container_add(GTK_CONTAINER(main_window_bracket_open_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_open_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_open_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_open_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING 0 BUTTON//
    main_window_0_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_0_button,1,2,5,6,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_0_button,30,50);
    g_signal_connect(G_OBJECT(main_window_0_button), "key_press_event", G_CALLBACK(key_press_cb), "0");
    g_signal_connect(main_window_0_button,"clicked",G_CALLBACK(writing_on_label),"0");
    gtk_widget_show(main_window_0_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new("0");
    gtk_container_add(GTK_CONTAINER(main_window_0_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_0_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_0_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_0_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING DECIMAL BUTTON//
    main_window_decimal_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_decimal_button,2,3,5,6,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_decimal_button,30,50);
    g_signal_connect(G_OBJECT(main_window_decimal_button), "key_press_event", G_CALLBACK(key_press_cb), ".");
    g_signal_connect(main_window_decimal_button,"clicked",G_CALLBACK(writing_on_label),".");
    gtk_widget_show(main_window_decimal_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new(".");
    gtk_container_add(GTK_CONTAINER(main_window_decimal_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_decimal_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_decimal_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_decimal_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //CREATING BRACKET CLOSE BUTTON//
    main_window_bracket_close_button = gtk_button_new();
    gtk_table_attach(GTK_TABLE(main_window_table),main_window_bracket_close_button,3,4,5,6,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,0,0);
    gtk_widget_set_size_request(main_window_bracket_close_button,30,50);
    g_signal_connect(G_OBJECT(main_window_bracket_close_button), "key_press_event", G_CALLBACK(key_press_cb), ")");
    g_signal_connect(main_window_bracket_close_button,"clicked",G_CALLBACK(writing_on_label),")");
    gtk_widget_show(main_window_bracket_close_button);
    /////////////////////////////////////////////////////////////////////////////////
    button_label = gtk_label_new(")");
    gtk_container_add(GTK_CONTAINER(main_window_bracket_close_button),button_label);
    gtk_widget_show(button_label);
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_close_button), GTK_STATE_ACTIVE, &color2 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_close_button), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_bracket_close_button), GTK_STATE_PRELIGHT, &color1 );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(button_label), GTK_STATE_PRELIGHT, &colorfg );
    ///////////////////////////////////////////////////////////////////////////////////
    //GDK COLOR FOR LABEL//
    gdk_color_parse( "#4f5b66", &color1 );
    gdk_color_parse( "##4f5b66", &color2 );
    gdk_color_parse( "#c0c5ce", &colorfg );
    //gtk_widget_modify_bg( GTK_WIDGET(drawingArea), GTK_STATE_NORMAL, &color1 );
    //////////////////////////////////////////////////////////////////////////////
    gtk_widget_modify_bg( GTK_WIDGET(main_window_window), GTK_STATE_ACTIVE, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_window), GTK_STATE_NORMAL, &color1 );
    gtk_widget_modify_bg( GTK_WIDGET(main_window_window), GTK_STATE_PRELIGHT, &color1 );
    ////////////////////////////////////////////////////////////////////////////////////
    gtk_widget_modify_fg( GTK_WIDGET(main_window_text), GTK_STATE_ACTIVE, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(main_window_text), GTK_STATE_NORMAL, &colorfg );
    gtk_widget_modify_fg( GTK_WIDGET(main_window_text), GTK_STATE_PRELIGHT, &colorfg );
    
    gtk_widget_show(main_window_window);
    g_signal_connect(main_window_window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_window_set_focus(main_window_window,NULL);//VVIMP...NULL MEANS NO WIDGET HAS FOCUS!!//
    gtk_main();
    return 0;
}
