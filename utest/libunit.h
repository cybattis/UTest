/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:38:29 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 19:01:47 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>

# define TIMEOUT 5
# define NO_LOG -1

typedef struct s_unit_test
{
	char	*test_name;
	int		(*f)(void);
	void	*next;
}	t_unit_test;

typedef struct s_test_data
{
	int		test_count;
	int		test_passed;
	int		test_failed_signal;
	pid_t	pid;
}	t_test_data;

void		launch_tests(t_unit_test **testlist, char *f_name, int fd);
void		load_test(t_unit_test **test_list, char *test_name, int (*f)(void));

void		print_test(t_unit_test *testlist, t_test_data *test_data, char *f_name);

void		print_test_status(int status);
void		print_result(int test_count, int test_passed);
void		log_test(t_unit_test *lst, t_test_data *t_data, char *f_name, int fd);
void		log_test_status(int status, int fd);
void		log_result(t_test_data test_data, int fd);

int			create_log_file(void);

t_unit_test	*ft_lstnew(char *test_name, int (*f)(void));
void		ft_lstadd_back(t_unit_test **alst, t_unit_test *new);
void		ft_lstdelone(t_unit_test *lst, void (*del)(void*));
void		ft_lstclear(t_unit_test **lst, void (*del)(void*));
int			ft_lstsize(t_unit_test *lst);

#endif
