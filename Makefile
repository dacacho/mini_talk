# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:36:58 by danierod          #+#    #+#              #
#    Updated: 2022/11/09 15:28:22 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

client	=	mandatory/client.c
			
server	=	mandatory/server.c

client_bonus	=	bonus/client_bonus.c

server_bonus	=	bonus/server_bonus.c

CNAME 	=	client

SNAME 	=	server

CNAME_B	=	client_bonus

SNAME_B	=	server_bonus

COBJECTS	=	$(client:.c=.o) 

SOBJECTS	=	$(server:.c=.o) 

COBJECTS_B	=	$(client_bonus:.c=.o)

SOBJECTS_B	=	$(server_bonus:.c=.o)

GCCW	=	gcc -Wall -Wextra -Werror

%.o:		%.c
			$(GCCW) -c $^ -o $@
	
m:		$(SNAME) $(CNAME)

b:		$(SNAME_B) $(CNAME_B)

all:	m b

$(CNAME): 	$(COBJECTS)
			$(GCCW) $^ -o $@ 

$(SNAME): 	$(SOBJECTS)
			$(GCCW) $^ -o $@

$(CNAME_B): $(COBJECTS_B)
			$(GCCW) $^ -o $@

$(SNAME_B): $(SOBJECTS_B)
			$(GCCW) $^ -o $@

clean:
			rm -rf $(COBJECTS)
			rm -rf $(SOBJECTS)
			rm -rf $(COBJECTS_B)
			rm -rf $(SOBJECTS_B)

fclean:		clean
			rm -rf $(CNAME)
			rm -rf $(SNAME)
			rm -rf $(CNAME_B)	
			rm -rf $(SNAME_B)
			
re:			fclean all

.PHONY:		all clean fclean re