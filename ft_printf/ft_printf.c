/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:58:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/02 12:00:38 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * 
 * va_start(ap, last_arg);:
 * Bu makro, ap (yani va_list değişkeniniz) içine, yığında last_arg'dan sonra gelen ilk variadic argümanın adresini yazar.
 * Assembly seviyesinde, last_arg'ın yığındaki adresini (genellikle EBP + ofset) alır ve üzerine last_arg'ın boyutunu ekleyerek ilk variadic argümanın adresine ulaşır.
 * Bu ofset, last_arg'ın kendisinin yığındaki konumu ve boyutu bilindiği için hesaplanabilir.

 * va_arg(ap, type);:
 * Bu makro, ap'nin şu anda işaret ettiği adresten, belirtilen type boyutunda veri okur.
 * Assembly seviyesinde:
 * ap'nin tuttuğu adresi alır.
 * Bu adresten sizeof(type) kadar bayt okur (veya tür yükseltmeleri nedeniyle daha büyük bir boyut, örneğin char ve short genellikle int olarak alınır).
 * ap'yi, okuduğu type'ın boyutunu bir sonraki argümanın başlangıcına işaret edecek şekilde artırır. (Yani ap = ap + sizeof(type); gibi basit bir ifade değil, çünkü mimarinin gerektirdiği hizalama kuralları da devreye girer.)
 * 
 * Hangi Parametreyi Alacağını Nereden Biliyor?

 * va_arg(ap, type) hangi parametreyi alacağını bilmez.
 * Sadece ap'nin şu an işaret ettiği yerden, senin belirttiğin type kadar bayt okur ve ap'yi ileri taşır.
 * Doğru parametreyi almak senin sorumluluğundadır.
 * Yani, printf format stringini parse ederek (%d gördüğünde int alması gerektiğini bilir)
 * va_arg'ı doğru type ile çağırmak zorundadır.
 * Yanlış tip belirtirsen, sonuç tanımsız davranış olur (yanlış sayıda bayt okur, yanlış yorumlar).
 * 
 * Linux x64'te (System V AMD64 ABI):

 * İlk 6 tam sayı veya pointer parametresi RDI, RSI, RDX, RCX, R8, R9 kaydedicilerine atanır.

 * İlk 8 kayan nokta parametresi XMM0 - XMM7 kaydedicilerine atanır.

 * Eğer daha fazla parametre varsa, bunlar yığına itilir.
 
 * reg_save_area: Bu, kaydedicilere atanmış ilk birkaç argümanın yedek kopyalarının tutulduğu bir bellek alanıdır. va_start bu alanı işaret eder.

 * gp_offset: Genel amaçlı kaydedicilerden (RDI, RSI vb.) kaç bayt ileride olduğunuzu tutar. va_arg her bir tam sayı/pointer argümanı aldığında bu ofseti günceller.

 * fp_offset: Kayan nokta kaydedicilerinden (XMM0 vb.) kaç bayt ileride olduğunuzu tutar. va_arg her bir kayan nokta argümanı aldığında bu ofseti günceller.

 * overflow_arg_area: Eğer parametreler kaydedicilere sığmaz ve yığına taşarsa, bu alan yığındaki taşan argümanların başlangıcını işaret eder.
 * 
// Örnek: Linux x64 ABI için
typedef struct
{
    unsigned int gp_offset;      // Offset for general purpose registers (RDI, RSI, RDX, RCX, R8, R9)
    unsigned int fp_offset;      // Offset for floating point registers (XMM0-7)
    void         *overflow_arg_area; // Pointer to the stack area for arguments that overflowed registers
    void         *reg_save_area; // Pointer to where the initial register arguments are saved on the stack
} va_list[1]; // va_list'in kendisi genellikle bir dizi (array of 1 element) olarak tanımlanır,
              // bu da onu bir pointer gibi davranmasını sağlar.
*/

static char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == 0)
			break ;
		s++;
	}
	return (0);
}

static ssize_t	handle_formatters(va_list args, int type)
{
	if (type == 'c')
		return (handle_char(args));
	else if (type == 's')
		return (handle_str(args));
	else if (type == '%')
		return (handle_percent());
	else if (type == 'd' || type == 'i')
		return (handle_int(args));
	else if (type == 'u')
		return (handle_uint(args));
	else if (type == 'x' || type == 'X')
		return (handle_hex(args, type));
	else if (type == 'p')
		return (handle_ptr(args));
	else
	{
		write(1, "%", 1);
		write(1, &type, 1);
		return (2);
	}
}

static ssize_t handle_error(const char *fmt, ssize_t written, int *count, va_list args)
{
	if (!fmt)
	{
		*count = -1;
		return (-1);
	}
	if (written == -1)
	{
		if (args)
			va_end(args);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	ssize_t	written;
	int		count;

	count = 0;
	written = 0;
	handle_error(fmt, written, &count, NULL);
	va_start(args, fmt);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
			written = handle_formatters(args, *(fmt + 1));
		else
			written = write(1, fmt, 1);
		if (handle_error(fmt, written, &count, args) == -1)
			return (-1);
		count += (int)written;
		if (*fmt == '%')
			fmt += 2;
		else
			fmt++;
	}
	va_end(args);
	return (count);
}
