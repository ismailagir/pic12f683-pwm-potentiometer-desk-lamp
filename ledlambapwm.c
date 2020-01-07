#include <12F683.h> 
//#include <Math.h> 

#device ADC=10
#use delay(int=8000000)

int eskipwm=0;
long int adc_res;   



void main()
{
   

    SETUP_ADC_PORTS(sAN0|VSS_VDD );
    setup_adc(adc_clock_internal);
    SET_ADC_CHANNEL(0);

    enable_interrupts(GLOBAL);
   
   // SETUP_TIMER_2(T2_DIV_BY_1, 9, 1);
    setup_timer_2(T2_DIV_BY_1,255,1); 

    setup_comparator(NC_NC);
    setup_ccp1(CCP_PWM);
    
    setup_oscillator(OSC_8MHZ);
    
    //printf("Ion\n\r");
    set_pwm1_duty(0);
    while(1){
    
      adc_res=read_adc();
for(int f=0;f<100;f++)
{
adc_res=read_adc()+adc_res;
 delay_ms(1);
}
if((adc_res/101-eskipwm)>50)
{
set_pwm1_duty(adc_res/101);
eskipwm=adc_res/101;}
adc_res=0;
      
         
     
     }
  
    }


