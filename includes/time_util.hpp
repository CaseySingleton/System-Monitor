/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:39:50 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 21:39:51 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTIL_H
# define TIME_UTIL_H

# include <time.h>

# define NSEC_IN_SEC 1000000000L

long			time_subtract(struct timespec a, struct timespec b);
struct timespec	time_add(struct timespec t, long n);

#endif
