Action2()
{
	
	int masPass[10];
	int masCost[10];
	int i;
	int x;
	int temp1;
	int temp2;
	
	web_reg_save_param_regexp(
		"ParamName=countPas",
		"RegExp=<b>&nbsp;&nbsp;([0-9]*)",
		"Ordinal=All",
		SEARCH_FILTERS,
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=TotalCost",
		"LB=Total Charge: $ ",
		"RB= <BR/>",
		"Ordinal=All",
		SEARCH_FILTERS,
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	masPass[0] = atoi(lr_eval_string("{countPas_1}"));
	masPass[1] = atoi(lr_eval_string("{countPas_2}"));
	masPass[2] = atoi(lr_eval_string("{countPas_3}"));
	masPass[3] = atoi(lr_eval_string("{countPas_4}"));
	masPass[4] = atoi(lr_eval_string("{countPas_5}"));
	masPass[5] = atoi(lr_eval_string("{countPas_6}"));
	masPass[6] = atoi(lr_eval_string("{countPas_7}"));
	masPass[7] = atoi(lr_eval_string("{countPas_8}"));
	masPass[8] = atoi(lr_eval_string("{countPas_9}"));
	masPass[9] = atoi(lr_eval_string("{countPas_10}"));

	masCost[0] = atoi(lr_eval_string("{TotalCost_1}"));
	masCost[1] = atoi(lr_eval_string("{TotalCost_2}"));
	masCost[2] = atoi(lr_eval_string("{TotalCost_3}"));
	masCost[3] = atoi(lr_eval_string("{TotalCost_4}"));
	masCost[4] = atoi(lr_eval_string("{TotalCost_5}"));
	masCost[5] = atoi(lr_eval_string("{TotalCost_6}"));
	masCost[6] = atoi(lr_eval_string("{TotalCost_7}"));
	masCost[7] = atoi(lr_eval_string("{TotalCost_8}"));
	masCost[8] = atoi(lr_eval_string("{TotalCost_9}"));
	masCost[9] = atoi(lr_eval_string("{TotalCost_10}"));
	   

	for (i = 0; i<10; i++) {
	      for (x = i+1; x<10; x++){
			if (masPass[i]>masPass[x]){
	                  temp1 = masPass[i];
	                  masPass[i] = masPass[x];
	                  masPass[x] = temp1;
	                  
	                  temp2 = masCost[i];
	                  masCost[i] = masCost[x];
	                  masCost[x] = temp2;
	           	}
	      }        
  	}
	                                                                                                                                                                                                                                                                                                                                                                 
	for (i = 0; i<10; i++){
		lr_save_int(masPass[i], "PassKol");
		lr_output_message("Number of passenger is: %s",lr_eval_string("{PassKol}"));
		lr_save_int(masCost[i], "CostSum");
		lr_output_message("Summary cost of this ticket is: %s$",lr_eval_string("{CostSum}"));
		lr_output_message("________________________________________");		
	}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	return 0;
}
