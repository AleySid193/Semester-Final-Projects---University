#pragma once
class superadmin
{
protected:
	void superadmin_login_check();
};
class admin
{
protected:
	void admin_login_check();
};
class doctor
{
protected:
	void doctor_login_check();
	void citizen_vaccine_status();
};
class fdo 
{
protected:
	void fdo_login_check();
};
class government_official
{
protected:
	void government_officer_check();
};
class citizen
{
public:
	void citizen_account_check();
	bool citizen_account_signUp_or_logIn();
};
class main_menu : 
	public doctor, 
	public government_official, 
	public fdo, 
	public superadmin, 
	public admin, 
	public citizen
{
private:
	char a , account_type_choice='a';
public:
	void welcome_note();
	void account_type();
};
