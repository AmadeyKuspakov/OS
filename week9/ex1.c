#include<stdio.h>

#include<sys/types.h>

#include<unistd.h>

#define TRUE 1

#define FALSE 0;

struct oneFrame{

	int referenced;

	int lifespan;

	int pageAddress;

};


int length;

struct oneFrame *frames;

int getIntShiftBitsAmount(){

	return sizeof(int) * 8;

}

int rightShift(int initialNumber, int shiftAmount){
    
    return (int)((unsigned int) initialNumber << shiftAmount);
    
}

int leftShift(int initialNumber, int shiftAmount){

	return (int)((unsigned int) initialNumber >> shiftAmount);

}

int binaryOr(int a, int b){

	return a|b;

}

int getNewReference(){

	int newAge = 1;

	return rightShift(newAge, getIntShiftBitsAmount() - 1);

}

int anyFreeFrame(){
    
    int i;
    
    for(i = 0; i<length; i++){
        
        if(!frames[i].referenced){
            
            return TRUE;
            
        }
        
    }
    
    return FALSE;
    
}

int getPositionOfMostAgedElement(){
    
    int i, min, position;
    
    for(i = 0; i<length; i++){
        
        if(min > frames[i].lifespan){
            
            min = frames[i].lifespan;
            
            position = i;
            
        }
        
    }
    
    return position;
    
}

int getPostionOfFreeFrame(){
    
    int i;
    
    for(i = 0; i<length; i++){
        
        if(!frames[i].referenced){
            
            return i;
            
        }
        
    }
    
    return -1;
    
}

int contains(int pageAddress){
    
    int i;
    
    for(i = 0; i<length; i++){
	        
        if(frames[i].pageAddress == pageAddress){
            
            return i;
            
        }

	}
	
	return -1;
	
}

void ageAllByOneStage(){
    
    int i;
	    
    for(i = 0; i<length; i++){
        
        frames[i].lifespan = leftShift(frames[i].lifespan, 1);
        
    }
    
}


void reference(int pageAddress){

	int i;
	
	if(!anyFreeFrame()){
	    
	    ageAllByOneStage();
	    
	    i = contains(pageAddress);
	    
	    if(i == -1){
	        
	        // there is no frame with such page address in the memory table
	        i = getPositionOfMostAgedElement();
	        
	        frames[i].lifespan = getNewReference();
	        
	        frames[i].pageAddress = pageAddress;
	        
	    }else{
	        
	        //there is one frame with such page address in the memory table
	        frames[i].lifespan = binaryOr(frames[i].lifespan, getNewReference());
	        
	    }
	    
	}else{
	    
	    i = getPostionOfFreeFrame();
	    
	    if(i == -1){
	        
	        printf("Something went wrong");
	        exit(1);
	        
	    }
	    
	    frames[i].referenced = TRUE;
	    
	    frames[i].lifespan = getNewReference();
	    
	    frames[i].pageAddress = pageAddress;
	    
	}

}

void printAll(){
    
    int i;
    
    for(i = 0; i<length; i++){
        
        printf("referenced: %d, lifespan: %d, pageAddress: %d\n", frames[i].referenced, frames[i].lifespan, frames[i].pageAddress);
        
    }
    
}

int main(){

	length = 3;
	struct oneFrame unoFrame;
	frames = malloc(sizeof(unoFrame) * length);
	frames[0].referenced = TRUE;
	frames[0].lifespan = 1;
	frames[0].pageAddress = 1;
	frames[1].referenced = TRUE;
	frames[1].lifespan = 1;
	frames[1].pageAddress = 2;
	frames[2].referenced = TRUE;
	frames[2].lifespan = 1;
	frames[2].pageAddress = 3;
	
	printAll();
	
	int i;

	for(i = 0; i<16; i++){
		reference(3);
	}
	//after these references lifespan of page address 3 is reduced 
	
	printAll();
	
	return 0;

}

