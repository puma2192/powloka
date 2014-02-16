char miejsce;

int pwd() //bfody funkcji pwd
{
  char buffer[256]; 

  if (!getcwd(buffer, 256)) { // po wpisaniu więcej niż 256 znaków polecenie będzie za długie 
    printf("za dluga\n");
  }
  else {
    printf("%s\n", buffer); // wyświetlenie miejsca gdzie aktualnie jesteśmy 
	miejsce = buffer; // przypisanie miejsca wpisanego przez użytkownika do buffera
  }
  
}
