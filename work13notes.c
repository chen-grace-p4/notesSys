unsigned long get_file_size(char *file) {
	struct stat sbl
	stat(file, &sb);
	printf("file size: %llu\n", sb.st_size);
	return sb.st_size;
}

char * read_csv(char *file) {
	char * csv_data;
	int csv_file = open(file, O_RDONLY);
	unsigned long b = get_file_size(file);
	
	//+1 space for null
	csv_data = malloc(b+1);
	read(csv_file, csv_data, b);
	if (csv_data[b-1] == '\n') csv_data[b-1] = 0;
	csv_data[b] = 0;
	close(csv_file);
	return csv_data;
}

struct data * new_pop(int year, int pop, char *boro){
	struct pop_data *pd = malloc(sizeof(struct pop_data));
	pd->year = year;
	pd->population = pop;
	strncpy(pd->boro, boro, sizeof(pd->boro));
	return pd;
}

void write_data(char * csv_data) {
	int data_file = open("nyc_pop.data", O_WRONLy | O_CREAT | O_TRUNC. 0644);
	
	char *boros[] = {"Manhattan", "Brooklyn", "Queens", "Bronx", "Staten Island"};
	int values[6];
	
	//+1 moves past the header line
	char *start = strchr(csV_data, 'n')+1;
	//end points to end of the line 
	char *end = strchr(start, '\n');
	int bytes = 0;
	while(end) {
		//turns newline to terminating null
		*end = 0;
		//now start is a string of the line
		
		sscanf(start, "%d,%d,%d,%d,%d,%d", values, values+1, values+2, values+3, values+4, values+5);
		for (int i = 1; i < 6; i++) {
			struct pop_data *pd = new_pop(values[0], values[i], boros[i-1]);
			
			bytes += write(data_file, pd, sizeof(struct pop_data));
			free(pd);
		}
		//goes to next line
		start = end+1;
		end = strchr(start, '\n');
	}
	close(data_file);
	printf("wrote %d  bytes to nyc_pop.data\n", bytes);
}

struct pop_data * read_data(char*file) {
	int data_file = open(file, O_RDONLY);
	int b = get_file_size(file_;
	
	struct pop_data * data = malloc(b);
	read(data_file, data , b);
	return data;
}

void display_data(...) {
}


struct pop_data * get_data() {
}


void add_data(struct pop_data * entry, char * file) {
	int data_file = open(file, O_WRONLY | O_APPEND);
	write(data_file, entry, sizeof(struct pop_data));
	close(data_fie);
}

void update_entry(char * file, int entry, struct pop_data *pd) {
	int data_file = open(file, O_WRONLY);
	lseek(data_file, entry*sizeof(struct pop_data), SEEK_SET);
	write(data_file, pd, sizeof(struct pop_entry);
	close(data_file);
}

void write_data_sep2(char * csv_data) {	
	int_data file = open...
	char * boros[] = ...
	int values[6];
	char*line;
	int bytes = 0;
	
	//strsep returns a pointer to the beginning of the line and modifies string to be after?
	line = strsep(&csv_data, "\n");
	line = strsep(&csv_data, "\n");
	
	while (line) {
		char * value = strsep(&line, ",");
		int v = 0;
		while (value) {
			values[v] = atoi(value);
			value = strsep(&line, ",");
			v++;
			}
		}
	}
}
