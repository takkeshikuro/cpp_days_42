#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public :
		Contact(void);
		~Contact(void);

		int			index;
		void add_contact();
		void print_tab_line();
		void print_index_found();

	private :
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_nb;
		std::string _dark_secret;
		
};

std::string if_tab(const std::string s);
int noblank(std::string line);

#endif
