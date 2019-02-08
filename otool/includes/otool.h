/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:46 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/08 11:30:48 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# define BYTES_PER_ROW 16
# define PRINT_ROW_SIZE (BYTES_PER_ROW * 3) + 1

# ifdef __APPLE__

#  define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

# else

#  define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

int			display_usage(void);

void		print_file_name(t_nm_otool *nm_otool, char *current_file);

bool		display_row(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *index, uint64_t *position);

bool		display_byte(t_nm_otool *nm_otool, unsigned char **byte,
				uint64_t *index, uint64_t *position);

#endif
