/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/20 17:23:08 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putchar(char c);
int		ft_printf(char *str, ...);

int	

int puiss10(int i)
{
	int res;
	res = 1;
	while (i)
	{
		res *=10;
	}
	return (res);
}

int		main(int ac, char **av)
{
	float res = 1234.567;
	char res2 = -120;
	unsigned long long reslong = 184467440737095516;
	char	str[] = {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin et turpis suscipit, tristique quam vitae, commodo lectus. Curabitur ut posuere massa, a eleifend purus. In hac habitasse platea dictumst. Nullam aliquam urna massa, id efficitur ipsum consectetur ac. Cras ac gravida est. Nulla porta maximus mi, vitae semper ex vestibulum ac. Donec faucibus semper risus, eu euismod nisi congue ac. Curabitur ornare ante sed eros tempus, vitae aliquam ex dictum. Ut sit amet sagittis sem. Quisque pretium posuere tellus, quis porta mi malesuada in. Etiam varius erat libero, a vestibulum felis pellentesque ut. Suspendisse aliquet luctus elit et fringilla. Pellentesque fermentum leo ac enim convallis vehicula.Duis vestibulum facilisis tortor non rutrum. Morbi fringilla erat at malesuada pretium. Nunc varius quam id ipsum condimentum sagittis sit amet a nibh. Mauris ut varius sapien. Etiam placerat metus in arcu semper, ac sodales urna volutpat. Nunc viverra diam vel neque pharetra malesuada. Donec dictum mi vel mi accumsan, eget finibus ipsum blandit. Sed sit amet magna eu elit imperdiet ornare. Sed porta, felis in semper elementum, leo libero tincidunt metus, id tincidunt mi augue vulputate lectus. Aliquam faucibus sodales magna eget imperdiet. Maecenas ornare sit amet leo eu rutrum. In nec finibus est. Nunc dapibus pharetra rutrum. Vivamus sit amet purus sem. Cras convallis sit amet nunc vel laoreet.Donec laoreet, ipsum at varius imperdiet, sapien sem commodo neque, at condimentum velit nisi non purus. Pellentesque pharetra volutpat enim a tincidunt. Etiam ultricies ut mauris quis tempus. Vivamus non nisi molestie, condimentum diam vel, sodales ipsum. Etiam leo eros, sodales quis laoreet sed, commodo quis ipsum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus malesuada, ligula id efficitur fermentum, tortor urna tincidunt ex, eu condimentum lacus urna id tortor. Maecenas est nulla, malesuada vel sollicitudin vitae, sollicitudin quis ipsum. Aliquam aliquet metus vitae tellus dictum semper sed quis nulla. Suspendisse pharetra tortor nulla, ac mattis arcu elementum sit amet. Nulla et libero mi. Nam fermentum fermentum urna, eget tristique diam volutpat sit amet. Proin cursus, dolor sed malesuada ornare, elit justo iaculis tellus, in interdum lorem dolor eu augue. Vivamus lacinia feugiat erat eu efficitur. Donec condimentum quis erat ac faucibus.Aliquam fermentum nulla vitae mi ultricies, a vulputate risus rhoncus. Sed sollicitudin imperdiet tellus, vitae laoreet est iaculis sit amet. Nam egestas eget ex ut malesuada. Vestibulum dictum leo sed nunc blandit consequat. Aenean hendrerit ante a sollicitudin tincidunt. Phasellus et metus diam. Duis ac sem turpis. Aliquam gravida iaculis congue. Fusce ullamcorper efficitur enim sed tempor. Etiam fringilla est sit amet magna bibendum, vel condimentum mauris volutpat. In aliquam pharetra facilisis. Maecenas vulputate suscipit lacus quis dapibus. Proin vel quam cursus, ultricies libero ut, maximus turpis. Donec imperdiet dictum tincidunt. Phasellus tincidunt massa nisl, ut feugiat neque mollis euismod. Etiam ullamcorper facilisis massa quis sollicitudin. Sed lacinia lacus enim, et volutpat dui sagittis at. Aenean lacinia diam velit, id tincidunt lectus aliquet nec. Donec nec mauris tristique urna rutrum posuere. Mauris varius risus scelerisque felis placerat eleifend. Vestibulum aliquam, turpis vestibulum sagittis efficitur, magna neque vulputate ante, in porta orci sapien vitae dui. Fusce ligula neque, accumsan sit amet ipsum quis, dapibus sodales lectus. Mauris nec ipsum metus. "};
//	printf("v|%.10s|\n", str);
//	ft_printf("f|%.10s|\n", str);
//	printf("%  ");
	printf("|%-35.25f|\n", res);
	printf("|%.25lf|\n", -10000000005000000000000000.0 / 10000000005000000000000000.0);
}
