# 1 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c"
# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_search_row(PVCI pvci, char * columnNames, char * messages, char * delimiter, char * **outcolumns, char * **outvalues);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);
VTCERR   vtc_update_all_message_ifequals(PVCI pvci, char * columnNames, char * message, char * ifmessage, char * delimiter, unsigned short *outRc);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_connect_ex(char * vtc_first_param, ...);
VTCERR   lrvtc_connect_ex_no_ellipsis(const char *vtc_first_param, char ** arguments, int argCount);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_search_row(char * columnNames, char * messages, char * delimiter);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);
VTCERR   lrvtc_update_all_message_ifequals(char * columnNames, char * message, char * ifmessage, char * delimiter);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_search_row(PVCI2 pvci, char *columnNames, char *messages, char *delimiter, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
 
 
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_search_row(char *columnNames, char *messages, char *delimiter);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2












 
 











# 3 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
	web_cache_cleanup();

	web_cleanup_auto_headers();

	web_cleanup_cookies();

	return 0;
}
# 4 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC01_Login.c" 1
UC01_Login()
{

	lr_start_transaction("UC01_Login");

		lr_start_transaction("UC01_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t97.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t98.inf", 
		"Mode=HTTP", 
		"LAST");

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=A Session ID has been created and loaded into a cookie called MSO",
		"LAST");

		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		"LAST");
	
	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t100.inf", 
		"Mode=HTTP", 
		"LAST");
		
	web_reg_save_param_ex(
    "ParamName=userSession_1",
    "LB=name=\"userSession\" value=\"",
    "RB=\"",
    "SEARCH_FILTERS",
    "Scope=Body",
    "RequestUrl=*/nav.pl*",
    "LAST");

	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t101.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC01_01_Home_page", 2);


	lr_start_transaction("UC01_02_Login");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(25);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		"LAST");

	web_submit_data("login.pl", 
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t102.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=userSession", "Value={userSession_1}", "ENDITEM", 
		"Name=username", "Value={Login}", "ENDITEM", 
		"Name=password", "Value={Password}", "ENDITEM", 
		"Name=login.x", "Value=24", "ENDITEM", 
		"Name=login.y", "Value=9", "ENDITEM", 
		"Name=JSFormSubmit", "Value=off", "ENDITEM", 
		"LAST");

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t103.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t104.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC01_02_Login", 2);


	lr_start_transaction("UC01_03_Sign_off");

		web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(4);
	
	
	web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t105.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t106.inf", 
		"Mode=HTTP", 
		"LAST");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"userSession\"",
		"LAST");

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t107.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC01_03_Sign_off", 2);

	lr_end_transaction("UC01_Login", 2);



	return 0;
}
# 5 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC02_Search_ticket_without_purchasing.c" 1
UC02_Search_ticket_without_purchasing()
{
lr_start_transaction("UC02_Search_ticket_without_purchasing");

		
	lr_start_transaction("UC02_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t108.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t109.inf", 
		"Mode=HTTP", 
		"LAST");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		"LAST");

	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t110.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t111.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC02_01_Home_page", 2);

	lr_start_transaction("UC02_02_Login");

 
	web_reg_save_param_ex(
		"ParamName=userSession_1",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/nav.pl*",
		"LAST");

	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t112.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(28);
	
		
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		"LAST");

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t113.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=userSession", "Value={userSession_1}", "ENDITEM",
		"Name=username", "Value={Login}", "ENDITEM",
		"Name=password", "Value={Password}", "ENDITEM",
		"Name=login.x", "Value=41", "ENDITEM",
		"Name=login.y", "Value=4", "ENDITEM",
		"Name=JSFormSubmit", "Value=off", "ENDITEM",
		"LAST");

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t114.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t115.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_end_transaction("UC02_02_Login", 2);


	lr_think_time(22);

	lr_start_transaction("UC02_03_Ticket_search");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User has returned to the search page.",
		"LAST");


		web_url("Search Flights Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t116.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t117.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("reservations.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t119.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC02_03_Ticket_search", 2);

	lr_start_transaction("UC02_04_Fill_date");

		
	web_add_auto_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(24);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"seatType\" value=\"{seatType}\" ",
		"LAST");
	
	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\" checked",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/reservations.pl*",
		"LAST");

	web_submit_data("reservations.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t123.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=depart", "Value={depart}", "ENDITEM", 
		"Name=departDate", "Value={departDate}", "ENDITEM", 
		"Name=arrive", "Value={arrive}", "ENDITEM", 
		"Name=returnDate", "Value={returnDate}", "ENDITEM", 
		"Name=numPassengers", "Value=1", "ENDITEM", 
		"Name=seatPref", "Value={seatPref}", "ENDITEM", 
		"Name=seatType", "Value={seatType}", "ENDITEM", 
		"Name=findFlights.x", "Value=62", "ENDITEM", 
		"Name=findFlights.y", "Value=12", "ENDITEM", 
		"Name=.cgifields", "Value=roundtrip", "ENDITEM", 
		"Name=.cgifields", "Value=seatType", "ENDITEM", 
		"Name=.cgifields", "Value=seatPref", "ENDITEM", 
		"LAST");

	lr_think_time(5);

	lr_end_transaction("UC02_04_Fill_date", 2);

lr_start_transaction("UC02_05_Select_ticket");

			web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"firstName\" value=\"{Login}\" ",
		"LAST");
		
	web_submit_data("reservations.pl_3", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t124.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=outboundFlight", "Value={outboundFlight}", "ENDITEM", 
		"Name=numPassengers", "Value=1", "ENDITEM", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=seatType", "Value={seatType}", "ENDITEM", 
		"Name=seatPref", "Value={seatPref}", "ENDITEM", 
		"Name=reserveFlights.x", "Value=42", "ENDITEM", 
		"Name=reserveFlights.y", "Value=5", "ENDITEM", 
		"LAST");


	lr_end_transaction("UC02_05_Select_ticket", 2);


	lr_end_transaction("UC02_Search_ticket_without_purchasing", 2);

	return 0;
}
# 6 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC03_Buy_ticket.c" 1
UC03_Buy_ticket()
{

	lr_start_transaction("UC03_Buy_ticket");

		lr_start_transaction("UC03_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t125.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t126.inf", 
		"Mode=HTTP", 
		"LAST");

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		"LAST");

	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t127.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t128.inf", 
		"Mode=HTTP", 
		"LAST");

		web_reg_save_param_ex(
    "ParamName=userSession_1",
    "LB=name=\"userSession\" value=\"",
    "RB=\"",
    "SEARCH_FILTERS",
    "Scope=Body",
    "RequestUrl=*/nav.pl*",
    "LAST");
		
	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t129.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC03_01_Home_page", 2);


	lr_start_transaction("UC03_02_Login");

		web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(23);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		"LAST");

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t130.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=userSession", "Value={userSession_1}", "ENDITEM",
		"Name=username", "Value={Login}", "ENDITEM",
		"Name=password", "Value={Password}", "ENDITEM",
		"Name=login.x", "Value=58", "ENDITEM",
		"Name=login.y", "Value=10", "ENDITEM",
		"Name=JSFormSubmit", "Value=off", "ENDITEM",
		"LAST");


	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t131.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t132.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC03_02_Login", 2);


	lr_start_transaction("UC03_03_Search_ticket");

		web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(18);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User has returned to the search page.",
		"LAST");

	web_url("Search Flights Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t133.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("reservations.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t134.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t135.inf", 
		"Mode=HTTP", 
		"LAST");
	
	lr_end_transaction("UC03_03_Search_ticket", 2);

	lr_start_transaction("UC03_04_Select_date");

		 

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(51);
	
	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\" checked",
		"SEARCH_FILTERS",
		"Scope=Body",
		"RequestUrl=*/reservations.pl*",
		"LAST");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"seatType\" value=\"{seatType}\" ",
		"LAST");

	web_submit_data("reservations.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t136.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=depart", "Value={depart}", "ENDITEM", 
		"Name=departDate", "Value={departDate}", "ENDITEM", 
		"Name=arrive", "Value={arrive}", "ENDITEM", 
		"Name=returnDate", "Value={returnDate}", "ENDITEM", 
		"Name=numPassengers", "Value=3", "ENDITEM", 
		"Name=seatPref", "Value={seatPref}", "ENDITEM", 
		"Name=seatType", "Value={seatType}", "ENDITEM", 
		"Name=findFlights.x", "Value=40", "ENDITEM", 
		"Name=findFlights.y", "Value=5", "ENDITEM", 
		"Name=.cgifields", "Value=roundtrip", "ENDITEM", 
		"Name=.cgifields", "Value=seatType", "ENDITEM", 
		"Name=.cgifields", "Value=seatPref", "ENDITEM", 
		"LAST");
	web_set_max_html_param_len("99999999");

	lr_end_transaction("UC03_04_Select_date", 2);
	

	lr_start_transaction("UC03_05_Select_time");

		 

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(20);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"firstName\" value=\"{Login}\"",
		"LAST");

	web_submit_data("reservations.pl_3", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t138.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=outboundFlight", "Value={outboundFlight}", "ENDITEM", 
		"Name=numPassengers", "Value=3", "ENDITEM", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=seatType", "Value={seatType}", "ENDITEM", 
		"Name=seatPref", "Value={seatPref}", "ENDITEM", 
		"Name=reserveFlights.x", "Value=72", "ENDITEM", 
		"Name=reserveFlights.y", "Value=9", "ENDITEM", 
		"LAST");


	lr_end_transaction("UC03_05_Select_time", 2);

	lr_start_transaction("UC03_06_Payment_detaills");

		 

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(20);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Thank you for booking through Web Tours.",
		"LAST");

	web_submit_data("reservations.pl_4", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t140.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=firstName", "Value={Login}", "ENDITEM", 
		"Name=lastName", "Value={Password}", "ENDITEM", 
		"Name=address1", "Value={address1}", "ENDITEM", 
		"Name=address2", "Value={address2}", "ENDITEM", 
		"Name=pass1", "Value={pass1}", "ENDITEM", 
		"Name=pass2", "Value={pass1}1", "ENDITEM", 
		"Name=pass3", "Value={pass1}2", "ENDITEM", 
		"Name=creditCard", "Value={creditCard}", "ENDITEM", 
		"Name=expDate", "Value={expDate}", "ENDITEM", 
		"Name=oldCCOption", "Value=", "ENDITEM", 
		"Name=numPassengers", "Value=3", "ENDITEM", 
		"Name=seatType", "Value={seatType}", "ENDITEM", 
		"Name=seatPref", "Value={seatPref}", "ENDITEM", 
		"Name=outboundFlight", "Value={outboundFlight}", "ENDITEM", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=returnFlight", "Value=", "ENDITEM", 
		"Name=JSFormSubmit", "Value=off", "ENDITEM", 
		"Name=buyFlights.x", "Value=28", "ENDITEM", 
		"Name=buyFlights.y", "Value=11", "ENDITEM", 
		"Name=.cgifields", "Value=saveCC", "ENDITEM", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");


	lr_end_transaction("UC03_06_Payment_detaills", 2);

	lr_start_transaction("UC03_07_Tickets_list");

		lr_think_time(16);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t142.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t143.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
		
		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= {Login} {Password}",
		"LAST");

	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t145.inf", 
		"Mode=HTTP", 
		"LAST");

	 

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(12);


	lr_end_transaction("UC03_07_Tickets_list", 2);

	lr_start_transaction("UC03_08_Sign_off");

		web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t149.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t150.inf", 
		"Mode=HTTP", 
		"LAST");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=<title>Web Tours Navigation Bar</title>",
		"LAST");

	web_url("nav.pl_5", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t151.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC03_08_Sign_off", 2);

	lr_end_transaction("UC03_Buy_ticket", 2);



	return 0;
}
# 7 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC04_Tickets_list.c" 1
UC04_Tickets_list()
{

	lr_start_transaction("UC04_Tickets_list");

		lr_start_transaction("UC04_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t152.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t153.inf", 
		"Mode=HTTP", 
		"LAST");

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		"LAST");
		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t154.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t155.inf", 
		"Mode=HTTP", 
		"LAST");

		
		web_reg_save_param_ex(
    "ParamName=userSession_1",
    "LB=name=\"userSession\" value=\"",
    "RB=\"",
    "SEARCH_FILTERS",
    "Scope=Body",
    "RequestUrl=*/nav.pl*",
    "LAST");
	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t156.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC04_01_Home_page", 2);


	lr_start_transaction("UC04_02_Login");

		web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(24);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		"LAST");

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t157.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=userSession", "Value={userSession_1}", "ENDITEM",
		"Name=username", "Value={Login}", "ENDITEM",
		"Name=password", "Value={Password}", "ENDITEM",
		"Name=login.x", "Value=81", "ENDITEM",
		"Name=login.y", "Value=6", "ENDITEM",
		"Name=JSFormSubmit", "Value=off", "ENDITEM",
		"LAST");

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t158.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t159.inf", 
		"Mode=HTTP", 
		"LAST");


	lr_end_transaction("UC04_02_Login", 2);

	lr_start_transaction("UC04_03_Tikcets_list");

		 

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(29);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t160.inf", 
		"Mode=HTTP", 
		"LAST");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text={Login} {Password}",
		"LAST");

	
	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t161.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t162.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC04_03_Tikcets_list", 2);


	lr_start_transaction("UC04_04_Sign_off");

		 

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(23);

	web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t163.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t164.inf", 
		"Mode=HTTP", 
		"LAST");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=<title>Web Tours Navigation Bar</title>",
		"LAST");

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t165.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC04_04_Sign_off", 2);

	lr_end_transaction("UC04_Tickets_list", 2);



	return 0;
}
# 8 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC05_Removing_existing_ticket.c" 1
handle_request_params() {
    int i;
    int count = atoi(lr_eval_string("{flightIDs_count}"));
    char flightIDs_combined[1024] = "";
    char cgfields_combined[1024] = "";
    char* currentFlightID = "";

    for (i = 1; i <= count; i++) {
        char paramName[50];
        char flightIDBuffer[1024];
        char cgfieldBuffer[1024];

        sprintf(paramName, "{flightIDs_%d}", i);

        currentFlightID = lr_eval_string(paramName);

        sprintf(flightIDBuffer, "%sflightID=%s", (i == 1 ? "" : "&"), currentFlightID);

        sprintf(cgfieldBuffer, "%s.cgifields=%d", (i == 1 ? "" : "&"), i);

        strcat(flightIDs_combined, flightIDBuffer);
        strcat(cgfields_combined, cgfieldBuffer);
    }

    lr_output_message("Combined flightIDs string: %s", flightIDs_combined);
    lr_output_message("Combined .cgifields string: %s", cgfields_combined);

    lr_save_string(flightIDs_combined, "flightIDs_combined");
    lr_save_string(cgfields_combined, "cgfields_combined");

    return 0;
}



UC05_Removing_existing_ticket()
{

	lr_start_transaction("UC05_Removing_existing_ticket");

		lr_start_transaction("UC05_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t166.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t167.inf", 
		"Mode=HTTP", 
		"LAST");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		"LAST");	
		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t168.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t169.inf", 
		"Mode=HTTP", 
		"LAST");

	web_reg_save_param_ex(
    	"ParamName=userSession_1",
    	"LB=name=\"userSession\" value=\"",
    	"RB=\"",
    	"SEARCH_FILTERS",
    	"Scope=Body",
    	"RequestUrl=*/nav.pl*",
    	"LAST");
		
	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t170.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC05_01_Home_page", 2);


	lr_start_transaction("UC05_02_Login");

		 

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(31);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		"LAST");

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t171.inf",
		"Mode=HTTP",
		"ITEMDATA",
		"Name=userSession", "Value={userSession_1}", "ENDITEM",
		"Name=username", "Value={Login}", "ENDITEM",
		"Name=password", "Value={Password}", "ENDITEM",
		"Name=login.x", "Value=40", "ENDITEM",
		"Name=login.y", "Value=3", "ENDITEM",
		"Name=JSFormSubmit", "Value=off", "ENDITEM",
		"LAST");

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t172.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t173.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC05_02_Login", 2);


	lr_start_transaction("UC05_03_Tickets_list");

		 

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(27);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t174.inf", 
		"Mode=HTTP", 
		"LAST");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text={Login} {Password}",
		"LAST");
	
	web_reg_save_param_regexp(
    	"ParamName=flightIDs",
    	"RegExp=input type=\"hidden\" name=\"flightID\" value=\"([^\"]+)\"",
    	"Ordinal=All",
    	"SEARCH_FILTERS",
    	"Scope=Body",
    	"LAST");

	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t175.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t176.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC05_03_Tickets_list", 2);


	lr_start_transaction("UC05_04_Remove_ticket");

		 

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(32);
	
	handle_request_params();
	web_custom_request("itinerary.pl_2",
    	"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl",
    	"Method=POST",
    	"Resource=0",
    	"RecContentType=text/html",
    	"Referer={protacol}://{host}:{port}/cgi-bin/itinerary.pl",
    	"Snapshot=t177.inf",
    	"Mode=HTTP",
    	"Body=1=on&{flightIDs_combined}&{cgfields_combined}&removeFlights.x=69&removeFlights.y=5",
    	"LAST");
	

	lr_end_transaction("UC05_04_Remove_ticket", 2);


	lr_start_transaction("UC05_05_Sign_off");

		 

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(30);

	web_url("welcome.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t179.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t180.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_think_time(7);

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t181.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC05_05_Sign_off", 2);

	lr_end_transaction("UC05_Removing_existing_ticket", 2);



	return 0;
}
# 9 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "UC06_New_user_registration.c" 1
char buff[32] = "";

random_word(char* param_name, int length)	{ 
  int r,i;
  char c;
  srand((unsigned int)_time32(0));

	for (i = 0; i < length; i++)	{
    	r = rand() % 26 + 97;
    	c = (char)r;
    	buff[i] = c;
    	printf("%c", c);
	}

	lr_save_string(buff, param_name);
	return 0;
}

UC06_New_user_registration()
{

	lr_start_transaction("UC06_New_user_registration");

		lr_start_transaction("UC06_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/",
		"Resource=0", 
		"Referer=", 
		"Snapshot=t182.inf", 
		"Mode=HTTP", 
		"LAST");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t183.inf", 
		"Mode=HTTP", 
		"LAST");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		"LAST");
		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t184.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t185.inf", 
		"Mode=HTTP", 
		"LAST");

		web_reg_save_param_ex(
    "ParamName=userSession_1",
    "LB=name=\"userSession\" value=\"",
    "RB=\"",
    "SEARCH_FILTERS",
    "Scope=Body",
    "RequestUrl=*/nav.pl*",
    "LAST");
	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t186.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC06_01_Home_page", 2);


	lr_start_transaction("UC06_02_Registration");

		 

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(29);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Please choose a username and password combination for your account.",
		"LAST");
	
	web_url("login.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/home.html", 
		"Snapshot=t187.inf", 
		"Mode=HTTP", 
		"LAST");

	(web_remove_auto_header("Upgrade-Insecure-Requests", "ImplicitGen=Yes", "LAST"));

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("profileValidate.js", 
		"URL={protacol}://{host}:{port}/WebTours/profileValidate.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t188.inf", 
		"LAST");

	lr_end_transaction("UC06_02_Registration", 2);


	lr_start_transaction("UC06_03_Filling_data");

		 

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(54);
	
	random_word("newUsername", 10);
	random_word("newPassword", 5);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Thank you, <b>{newUsername}</b>, for registering and welcome to the Web Tours family.",
		"LAST");

	web_submit_data("login.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t189.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=username", "Value={newUsername}", "ENDITEM", 
		"Name=password", "Value={newPassword}", "ENDITEM", 
		"Name=passwordConfirm", "Value={newPassword}", "ENDITEM", 
		"Name=firstName", "Value={newUsername}", "ENDITEM", 
		"Name=lastName", "Value={newPassword}", "ENDITEM", 
		"Name=address1", "Value=portland", "ENDITEM", 
		"Name=address2", "Value=portland", "ENDITEM", 
		"Name=register.x", "Value=66", "ENDITEM", 
		"Name=register.y", "Value=9", "ENDITEM", 
		"LAST");

	lr_end_transaction("UC06_03_Filling_data", 2);


	lr_start_transaction("UC06_04_Profile");

		 

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(48);

	web_url("button_next.gif", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t191.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("login.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t192.inf", 
		"Mode=HTTP", 
		"LAST");

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t193.inf", 
		"Mode=HTTP", 
		"LAST");

	lr_end_transaction("UC06_04_Profile", 2);

	lr_end_transaction("UC06_New_user_registration", 2);



	return 0;
}
# 10 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 11 "c:\\users\\admin\\documents\\vugen\\scripts\\webtoursscript\\\\combined_WebToursScript.c" 2

