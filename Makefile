# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:36:58 by danierod          #+#    #+#              #
#    Updated: 2022/11/08 17:41:07 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

client	=	client.c
			
server	=	server.c

CNAME 	=	client
SNAME 	=	server
COBJECTS	=	$(client:.c=.o)
SOBJECTS	=	$(server:.c=.o)
GCCW	=	gcc -Wall -Wextra -Werror

%.o:		%.c
			$(GCCW) -c $^ -o $@
	
all:		$(SNAME) $(CNAME)

$(CNAME): 	$(COBJECTS)
			$(GCCW) $^ -o $@ 

$(SNAME): 	$(SOBJECTS)
			$(GCCW) $^ -o $@

clean:
			rm -rf $(COBJECTS)
			rm -rf $(SOBJECTS)
			
fclean:		clean
			rm -rf $(CNAME)
			rm -rf $(SNAME)
			
re:			fclean all

.PHONY:		all clean fclean re