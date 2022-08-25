
#include <string.h>
#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>


/***
  Name : 

Submitted as  project for AKEANA training
  ***/



#define MAX_LABEL_LEN 20
#define MAX_SYMBOLS 255
#define MAX_LINE_LENGTH 255
int isOpcode(char *lptr);
  


/*****************global data ******************/
typedef struct{
  int address;
  char label[MAX_LABEL_LEN+1];   
} symboltable;

enum
{
   DONE, OK, EMPTY_LINE
};

int bin_instruction[32]; /*a binary array of integers to hold the instruction.*/
symboltable mytable[MAX_SYMBOLS]; /*** the array of symbol table ***/
int binary[5]; // holds the binary equivelent of register


FILE* infile = NULL;
FILE* outfile = NULL;

void store();
char* decToBin(int num, int length) {
 //This function will convert a decimal number to binary decimal immediates
}

char* hexToBin(int num, int length) {
 //This function will convert a Hex number to binary if you ar eusing hex immediates
}


char* sType(char* instruction) {
    //This function will convert all S type instruction into binary string
   
}

char* bType(char* instruction) {
        //This function will convert all B type instruction into binary string


   }

char* iType(char* instruction) {
        //This function will convert all I type instruction into binary string

    
}

char* RType(char* instruction) {
        //This function will convert all R type instruction into binary string

   }

char* uType(char* instruction ) {
        //This function will convert all U type instruction into binary string

  }

  char* jType(char* instruction) {
        //This function will convert all J type instruction into binary string

  }

  /*
    ************ calc_offset ***************
    takes current PC value and current label
    and returns the correct offset as integer
    returns 0  as faulty offset  because an
    offset of 0 means label to the very next instruction
*/
  int calc_offset(int curr_pc, char *curr_label)
{
  // Add yoru code here to caluclate the jump for PC
}

int readAndParse( FILE * pInfile, char * pLine, char ** pLabel, char
    ** pOpcode, char ** pArg1, char ** pArg2, char ** pArg3, char ** pArg4)
    {
            //this function will read lines from input file one by one . 
   
       char * lRet, * lPtr;
       int i;
       if( !fgets( pLine, MAX_LINE_LENGTH, pInfile ) )
        return( DONE );
       
           /* convert entire line to lowercase */
       for( i = 0; i < strlen( pLine ); i++ )
        pLine[i] = tolower( pLine[i] );
       
       *pLabel = *pOpcode = *pArg1 = *pArg2 = *pArg3 = *pArg4 = pLine + strlen(pLine);

       /* ignore the comments */
       lPtr = pLine;

       while( *lPtr != ';' && *lPtr != '\0' &&*lPtr != '\n' ) {
            lPtr++;
        }

       *lPtr = '\0';
       if( !(lPtr = strtok( pLine, "\t\n ," ) ) ) 
            return( EMPTY_LINE );

       if( isOpcode( lPtr ) == 0 && lPtr[0] != '.' )      
       {
       
            *pLabel = lPtr;
            if( !( lPtr = strtok( NULL, "\t\n ," ) ) ) return( OK );
       }
       
           *pOpcode = lPtr;

       if( !( lPtr = strtok( NULL, "\t\n ," ) ) ) return( OK );
       
      *pArg1 = lPtr;
       
      if( !( lPtr = strtok( NULL, "\t\n ," ) ) ) return( OK );

       *pArg2 = lPtr;
       if( !( lPtr = strtok( NULL, "\t\n ," ) ) ) return( OK );

       *pArg3 = lPtr;

       if( !( lPtr = strtok( NULL, "\t\n ," ) ) ) return( OK );

       *pArg4 = lPtr;

       return( OK );
    }
/************************************************************************************************/
// funt3 fnction
void funct3(char *lptr)
{
  if(strcmp(lptr,"add")==0 || strcmp(lptr,"sub")==0 || strcmp(lptr,"addi")==0 || strcmp(lptr,"lb")==0 || strcmp(lptr,"sb")==0 || strcmp(lptr,"beq")==0 || 
  strcmp(lptr,"jalr")==0 || strcmp(lptr,"ecall")==0 || strcmp(lptr,"ebreak")==0)
  {
    int arr[3]={0,0,0};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
/**********************************************************************/
 else if(strcmp(lptr,"sll")==0 || strcmp(lptr,"slli")==0 || strcmp(lptr,"lh")==0 || strcmp(lptr,"sh")==0 || strcmp(lptr,"bne")==0)
  {
    int arr[3]={0,0,1};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /***********************************************************************/
  else if(strcmp(lptr,"slt")==0 || strcmp(lptr,"slti")==0 || strcmp(lptr,"lw")==0 || strcmp(lptr,"sw")==0)
  {
    int arr[3]={0,1,0};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /*******************************************************************************/
  else if(strcmp(lptr,"sltu")==0 || strcmp(lptr,"sltiu")==0)
  {
    int arr[3]={0,1,1};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /*********************************************************************************/
  else if(strcmp(lptr,"xor")==0 || strcmp(lptr,"xori")==0 || strcmp(lptr,"lbu")==0 || strcmp(lptr,"blt")==0)
  {
    int arr[3]={1,0,0};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /*****************************************************************************************/
  else if(strcmp(lptr,"srl")==0 || strcmp(lptr,"sra")==0 || strcmp(lptr,"srli")==0 || strcmp(lptr,"sari")==0 || strcmp(lptr,"lhu")==0 || strcmp(lptr,"bge")==0)
  {
    int arr[3]={1,0,1};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /*******************************************************************************************/

  else if(strcmp(lptr,"or")==0 || strcmp(lptr,"ori")==0 || strcmp(lptr,"bltu")==0)
  {
    int arr[3]={1,1,0};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
  /***********************************************************************************************/

  else if(strcmp(lptr,"and")==0 || strcmp(lptr,"andi")==0 || strcmp(lptr,"bgeu")==0)
  {
    int arr[3]={1,1,1};
    for(int i=19; i>=17; i--)
    {
      bin_instruction[i]=arr[i-17];
    }
  }
}

/*************************************************************************************************************/



    // Function That convert the registers to crosponding binary value
    /******************************************************************************************************/
  

    void reg(char* lArg1)
{ 
      
    
      if((strcmp(lArg1,"x0")==0)||
          (strcmp(lArg1,"zero")==0))
        { 
          for(int i=0; i<5; i++) 
            {
               binary[i]=0;
            }
        }
      else if((strcmp(lArg1,"x1")==0) || (strcmp(lArg1,"ra")==0))
      {
          int arr[5]={0,0,0,0,1};
           for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
      }
    else if((strcmp(lArg1,"x2")==0) || (strcmp(lArg1,"sp")==0))
      {
            int arr[5]={0,0,0,1,0};
            for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
        

      }
    else if((strcmp(lArg1,"x3")==0) || (strcmp(lArg1,"gp")==0))
      {
          int arr[5]={0,0,0,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
        
      }
    else if((strcmp(lArg1,"x4")==0) || (strcmp(lArg1,"tp")==0))
      {
          int arr[5]={0,0,1,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
        

      }
    else if((strcmp(lArg1,"x5")==0) || (strcmp(lArg1,"t0")==0))
      {
          int arr[5]={0,0,1,0,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      } 
    else if((strcmp(lArg1,"x6")==0) || (strcmp(lArg1,"t1")==0))
      {
          int arr[5]={0,0,1,1,0};
           for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
       }

    else if((strcmp(lArg1,"x7")==0) || (strcmp(lArg1,"t2")==0))
      {
        int arr[5]={0,0,1,1,1};
           for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
    else if((strcmp(lArg1,"x8")==0) || (strcmp(lArg1,"s0")==0) || (strcmp(lArg1,"fp")==0))
      {
          int arr[5]={0,1,0,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
       }
    else if((strcmp(lArg1,"x9")==0) || (strcmp(lArg1,"s1")==0))
      {
        int  arr[5]={0,1,0,0,1};
        for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
      } 
 
    else if((strcmp(lArg1,"x10")==0) || (strcmp(lArg1,"a0")==0))
      {
          int arr[5]={0,1,0,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
        


      }     
    else if((strcmp(lArg1,"x11")==0) || (strcmp(lArg1,"a1")==0))
      {
          int arr[5]={0,1,0,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
        
      }     

    else if((strcmp(lArg1,"x12")==0) || (strcmp(lArg1,"a2")==0))
      {
          int arr[5]={0,1,0,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
        
      }     
    else if((strcmp(lArg1,"x13")==0) || (strcmp(lArg1,"a3")==0))
      {
          int arr[5]={0,1,0,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x14")==0) || (strcmp(lArg1,"a4")==0))
      {
          int arr[5]={0,1,1,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      } 
       else if((strcmp(lArg1,"x15")==0) || (strcmp(lArg1,"a5")==0))
      {
          int arr[5]={0,1,1,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }    
      }
       else if((strcmp(lArg1,"x16")==0) || (strcmp(lArg1,"a6")==0))
      {
          int arr[5]={1,0,0,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }

       else if((strcmp(lArg1,"x17")==0) || (strcmp(lArg1,"a7")==0))
      {
          int arr[5]={1,0,0,0,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x18")==0) || (strcmp(lArg1,"s2")==0))
      {
          int arr[5]={1,0,0,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x19")==0) || (strcmp(lArg1,"s3")==0))
      {
          int arr[5]={1,0,0,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x20")==0) || (strcmp(lArg1,"s4")==0))
      {
          int arr[5]={1,0,1,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x21")==0) || (strcmp(lArg1,"s5")==0))
      {
          int arr[5]={1,0,1,0,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x22")==0) || (strcmp(lArg1,"s6")==0))
      {
          int arr[5]={1,0,1,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x23")==0) || (strcmp(lArg1,"s7")==0))
      {
          int arr[5]={1,0,1,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
      else if((strcmp(lArg1,"x24")==0) || (strcmp(lArg1,"s8")==0))
      {
          int arr[5]={1,1,0,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x25")==0) || (strcmp(lArg1,"s9")==0))
      {
          int arr[5]={1,1,0,0,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x26")==0) || (strcmp(lArg1,"s10")==0))
      {
          int arr[5]={1,1,0,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x27")==0) || (strcmp(lArg1,"s11")==0))
      {
          int arr[5]={1,1,0,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x28")==0) || (strcmp(lArg1,"t3")==0))
      {
          int arr[5]={1,1,1,0,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x29")==0) || (strcmp(lArg1,"t4")==0))
      {
          int arr[5]={1,1,1,0,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x30")==0) || (strcmp(lArg1,"t5")==0))
      {
          int arr[5]={1,1,1,1,0};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       else if((strcmp(lArg1,"x31")==0) || (strcmp(lArg1,"t6")==0))
      {
          int arr[5]={1,1,1,1,1};
          for(int i=0; i<5; i++) 
            {
               binary[i]=arr[i];
            }
      }
       
    
}


/****************************************************************************************************************************/


int isOpcode(char *lptr)
    {
        if (
            (strcmp(lptr,"add")==0)||
            (strcmp(lptr,"sub")==0)||
            (strcmp(lptr,"xor")==0)||
            (strcmp(lptr,"or")==0)||
            (strcmp(lptr,"and")==0)||
            (strcmp(lptr,"sll")==0)||
            (strcmp(lptr,"srl")==0)||
            (strcmp(lptr,"sra")==0)||
            (strcmp(lptr,"slt")==0)||
            (strcmp(lptr,"sltu")==0))
            
            
        {
          int arr1[32]={1,1,0,0,1,1,0}; // opcode for R type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            
            
            
            return 1; // means its R type instruction
        } 
        /*********************************************/
        else if((strcmp(lptr,"addi")==0)||
            (strcmp(lptr,"xori")==0)||
            (strcmp(lptr,"ori")==0)||
            (strcmp(lptr,"andi")==0)||
            (strcmp(lptr,"slli")==0)||
            (strcmp(lptr,"srli")==0)||
            (strcmp(lptr,"srai")==0)||
            (strcmp(lptr,"slti")==0)||
            (strcmp(lptr,"sltiu")==0))
            
            
        {
          int arr1[32]={0,0,1,0,0,1,1}; // opcode for I type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            
            return 2;  // means I type instruction
        }       
        
    /**********************************************************************/

   else if ((strcmp(lptr,"lb")==0)||
            (strcmp(lptr,"lh")==0)||
            (strcmp(lptr,"lw")==0)||
            (strcmp(lptr,"lbu")==0)||
            (strcmp(lptr,"lhu")==0))
            
            
            
        {
          int arr1[32]={0,0,0,0,0,1,1}; // opcode for I type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            return 2; // I type instruction
        }
              
    /***************************************************************************/
  else if ((strcmp(lptr,"sb")==0)||
            (strcmp(lptr,"sh")==0)||
            (strcmp(lptr,"sw")==0))
           
            
            
        {
          int arr1[32]={0,1,0,0,0,1,1}; // opcode for S type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            return 3; // S type instructions
        }
                
    /***********************************************************************/
  else if((strcmp(lptr,"beq")==0)||
            (strcmp(lptr,"bne")==0)||
            (strcmp(lptr,"blt")==0)||
            (strcmp(lptr,"bge")==0)||
            (strcmp(lptr,"bltu")==0)||
            (strcmp(lptr,"bgeu")==0)
            )
            
            
        {
          int arr1[32]={1,1,0,0,0,1,1}; // opcode for B type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
             return 4; // B type instruction
        }

       
    /*****************************************************************************/
   else if ((strcmp(lptr,"jal")==0))
            
        {
          int arr1[32]={1,1,0,1,1,1,1}; // opcode for J type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            return 5; // J type
        }        
              
/********************************************************************************************/
else if ((strcmp(lptr,"jalr")==0))   
            
        {
          int arr1[32]={1,1,0,1,1,1,1}; // opcode for I type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
             return 2; // I type
        }        
       
/*********************************************************************************************/
 else if ((strcmp(lptr,"lui")==0) || (strcmp(lptr,"aupic")==0))   
            
        {
          int arr1[32]={0,1,1,0,1,1,1}; // opcode for U type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
              return 6; // U type Instruction
        }
      
/*************************************************************************************/

 else if ((strcmp(lptr,"ecall")==0) || (strcmp(lptr,"ebreak")==0))   
            
        {
          int arr1[32]={1,1,1,0,0,1,1}; // opcode for R type instruction
            for(int i=31; i>=0; i--)
            {
               bin_instruction[i]=arr1[31-i]; // storing the opcode in the instruction array
            }
            return 2; // I type
        }
}
        
/***************************************************************************************/
int toNum( char * pStr )
{
   char lBuf[10];
   char * t_ptr;
   char * orig_pStr;
   int t_length,k;
   int lNum, lNeg = 0;
   orig_pStr = pStr;
   if( *pStr == 'x' )               /* Hex */
   { 
        pStr++;
        if( *pStr == '-' )             /* hex is negative */
        {
            lNeg = 1;
            pStr++;
        }
        t_ptr = pStr;
        t_length = strlen(t_ptr);
        for(k=0;k < t_length;k++)
        {
            if (!isxdigit(*t_ptr))
            {
                printf("Error: invalid hex operand, %s\n",orig_pStr);
                exit(4);
            }
            t_ptr++;
        }
        sprintf( lBuf, "0x%s", pStr );     /* convert hex string into integer */
        sscanf( lBuf, "%i", &lNum );
        if( lNeg )
            lNum = -lNum;
        return lNum;
       }
   else   
   {
        pStr++;
        if( *pStr == '-' )             /* dec is negative */
        {
            lNeg = 1;
            pStr++;
        }
        t_ptr = pStr;
        t_length = strlen(t_ptr);
        for(k=0;k < t_length;k++)
        {
            if (!isdigit(*t_ptr))
            {
                printf("Error: invalid decimal operand, %s\n",orig_pStr);
                exit(4);
            }
            t_ptr++;
        }
        lNum = atoi(pStr);
        if (lNeg)
            lNum = -lNum;
 
        return lNum;
   
    }
    
}


char bin2hex(int highbit){
  char  retval;
  int i;  
  unsigned char dec; /* declared char to be compatible with retval*/
  dec=0;

  /* this is an iterative algo working from msb to lsb */
  for( i=0; i < 4; i++){
    dec = 2*dec; /* add to the power of 2 */
    dec = dec+ bin_instruction[highbit-i];
  }

  if( dec > 9){ /* the hex value must be an alphabet */
    dec = dec - 10;
    retval = dec + 'A';
  } else{ /* the hex value is a number 0--9 */
    retval = dec + '0';
  }

  return retval;
}

/********************write_instruction**********************/
/* writes the instruction into the output file as a hex val*/
void write_instruction(){
  char a;
  /* first put the '0x' in the beginning of the line*/
  fputc('0', outfile);
  fputc('x', outfile);

  a = bin2hex(31);
  fputc(a, outfile);
// Add code for further nibbles here




  /** now put a newline at the end*/
  fputc('\n',outfile);
}

void write()
{
  FILE* fptr;
    fptr=fopen("file2.txt","a");
  
    
    
        for(int i=0; i<32; i++)
        {
            fprintf(fptr,"%d",bin_instruction[i]);
          
        }
        fprintf(fptr,"\n");
        
 
    fclose(fptr);
}
/*******************************************************************************************************/
      //storing the binary value of rd in instruction array
void store()
{
  for(int i=24; i>=20; i--)
  {
   bin_instruction[i]=binary[i-20];
  }
}

/*****************************************************************************************************************/

int main(int argc, char* argv[])
{  
     /* open the source file */
     infile = fopen(argv[1], "r"); //First file for reading
     outfile = fopen(argv[2], "w");// second file for writing machine language
     char c;
     char lLine[MAX_LINE_LENGTH + 1], *lLabel, *lOpcode, *lArg1,
          *lArg2, *lArg3, *lArg4;

    int lRet;
    int lRet1;
    int immediate_op;
     if (!infile) {
       printf("Error: Cannot open input file %s\n", argv[1]);
       exit(4);
     }
     if (!outfile) {
       printf("Error: Cannot open output file %s\n", argv[2]);
       exit(4);
     }

     
  /*look for the .orig statement*/  
   int start_adress = 0;
 
/****************************************************************/
   FILE * lInfile;
   FILE * lInfile2;

   lInfile = infile;  /* open the input file */
   lInfile2 = infile;
  int current_pc = 0;
  char *templabel;
  int index_table = 0;

/* *templabel = *lLabel;*/
    
      int n;
  do {
    lRet1 = readAndParse( lInfile, lLine, &lLabel,
      &lOpcode, &lArg1, &lArg2, &lArg3, &lArg4 );
     
       n=isOpcode(lOpcode);
       reg(lArg1);
       funct3(lOpcode);
       store();
       write();
       printf("%s\n",lArg1);
    // printf("%d", isOpcode(lOpcode));
     
     } while( lRet1 != DONE );
    

     
      
        printf("%d",n);
      
     
   fclose ( infile );     /* Now close files */
  fclose ( outfile);  
}


