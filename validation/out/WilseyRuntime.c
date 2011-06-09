goto runend; //jump over runtime library

    char buff[128]; //char buffer
    
    //boolean function getBool()
    run0: //start of function
    //code for function
    printf("boolean=");
    R[0] = R[0] + 1; //increment stack pointer
    fgets(buff, 128, stdin); //read chars from console
    if(((char)buff[0] == 't') || ((char)buff[0] == '1'))
    {
        MM[R[0]] = 1;
    }
    else
    {
        MM[R[0]] = 0;
    }
    //returning from function 'getBool'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 0; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function getInt()
    run1: //start of function
    //code for function
    printf("integer=");
    R[0] = R[0] + 1; //increment stack pointer
    scanf("%i%*c",&MM[R[0]]);
    //returning from function 'getInt'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 0; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //string function getString()
    run2: //start of function
    //code for function
    printf("string=");
    R[0] = R[0] + 1; //increment stack pointer
    fgets(buff, 128, stdin); //read chars from console
    R[8] = 0; //initialize string iterator
    do
    {
        R[7] = (int)buff[R[8]]; //read char from buffer
        if(!((R[7] == 32) //space
        || (R[7] == 95) //underscore
        || (R[7] >= 48 && R[7] <= 57) //number
        || (R[7] >= 65 && R[7] <= 90) //uppercase
        || (R[7] >= 97 && R[7] <= 122))) //lowercase
        R[7] = 95; //replace undefined char with underscore
        MM[R[0] + R[8]] = R[7]; //push char onto stack
        R[8] = R[8] + 1; //incremetn iterator
    }while(buff[R[8]] != '\n');
    MM[R[0] + R[8]] = 0; //null terminator
    do
    {
        R[5] = R[5] - 1; //next allocation memory location
        MM[R[5]] = MM[R[0] + R[8]]; //move char to string memory
        R[8] = R[8] - 1; //decrease iterator
    }while (R[8] >= 0); 
    MM[R[0]] = R[5]; //pointer to string goes on stack
    //returning from function 'getString'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 0; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function putBool(boolean b)
    run3: //start of function
    //code for function
    if(MM[R[2] - 1] == 0)
    {
        printf("false\n");
    }
    else
    {
        printf("true\n");
    }
    //immediate value 0
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = 0; //push value onto stack
    //returning from function 'putBool'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function putInt(integer i)
    run4: //start of function
    //code for function
    printf("%i\n", MM[R[2] - 1]);
    //immediate value 0
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = 0; //push value onto stack
    //returning from function 'putInt'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function putString(string s)
    run5: //start of function
    R[8] = MM[R[2] - 1]; //load start of string
    while(MM[R[8]] != 0) //while not null terminator
    {
        printf("%c",MM[R[8]]);
        R[8] = R[8] + 1;
    }
    printf("\n");
    //immediate value 0
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = 0; //push value onto stack
    //returning from function 'putString'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function sqrt(integer i)
    run6: //start of function
    //code for function
    R[0] = R[0] + 1; //increment stack pointer
    double sqrtVal;
    sqrtVal = (double)MM[R[2] - 1]; //load parametr
    MM[R[0]] = (int)sqrt(sqrtVal); //perform square root
    //returning from function 'sqrt'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //boolean function int2bool(integer i)
    run7: //start of function
    //code for function
    R[6] = MM[R[2] - 1]; //load parametr
    R[0] = R[0] + 1; //increment stack pointer
    if(R[6] != 0)
    {
        R[6] = 1;
    }
    MM[R[0]] = R[6]; //push value onto stack
    //returning from function 'int2Bool'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
    
    //integer function getBool(boolean b)
    run8: //start of function
    //code for function
    R[0] = R[0] + 1; //increment stack pointer
    MM[R[0]] = MM[R[2] - 1]; //just shuffle locations, no actual conversion necessary
    //returning from function 'bool2int'
    R[4] = R[2]; //move the current frame pointer out of the way
    R[2] = MM[R[4]]; //restore frame pointer from previous activation record
    R[6] = MM[R[4] + 2]; //load return address from stack
    R[0] = R[4] - 1; //set stack pointer to beginning of return destination
    R[4] = R[4] + 3; //set pointer to beginning of return value
    R[7] = MM[R[4]]; //load value from return source
    MM[R[0]] = R[7]; //store value to return destination
    goto *R[6]; //return to caller
runend: //end of runtime library
