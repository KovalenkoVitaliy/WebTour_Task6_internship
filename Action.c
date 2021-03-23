Action()
{
	int j;
	int count;
	int currentCountPassenger;

	count = 10;
	
	
	for (j=0; j<count; j++){
		
		currentCountPassenger = atoi(lr_eval_string("{COUNT}"));
	
		createTicket(currentCountPassenger);

	}
	
	return 0;
}