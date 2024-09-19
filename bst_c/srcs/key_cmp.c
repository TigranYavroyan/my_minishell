/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:01 by tigran            #+#    #+#             */
/*   Updated: 2024/09/19 13:30:16 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static int _strcmp_bst (const char* op1, const char* op2);
static int _key_cmp (const char* op1, const char* op2);

bool _less (const char* op1, const char* op2) {
    return (_key_cmp(op1, op2) < 0);
}

bool _greater (const char* op1, const char* op2) {
    return (_key_cmp(op1, op2) > 0);
}

bool _equal (const char* op1, const char* op2) {
    return (_key_cmp(op1, op2) == 0);
}

static int _strcmp_bst (const char* op1, const char* op2) {
    int i;

    i = 0;
	if (!op1 && !op2)
		return (0);
	else if (!op1)
		return (*op2);
	else if (!op2)
		return (*op1);

    while (op1[i] && op2[i])
    {
        if (op1[i] != op2[i])
            return (op1[i] - op2[i]);
        ++i;
    }

    return (op1[i] - op2[i]);
}

static int _key_cmp (const char* op1, const char* op2) {
    return _strcmp_bst(op1, op2);
}