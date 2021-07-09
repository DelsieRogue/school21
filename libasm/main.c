#include <printf.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

#define SIMPLE_STR "hello world"
#define EMPTY_STR ""
#define LONG_STR "Vivendum dignissim conceptam pri ut, ei vel partem audiam sapientem. Vel in dicant cetero phaedrum, usu populo interesset cu, eum ea facer nostrum pericula. Tation delenit percipitur at vix. Sea esse deserunt ei, no diam ubique euripidis has.Solum vituperata definitiones te vis, vis alia falli doming ea. Vivendum dignissim conceptam pri ut, ei vel partem audiam sapientem. An eos iusto solet, id mel dico habemus. Solum vituperata definitiones te vis, vis alia falli doming ea. Sea esse deserunt ei, no diam ubique euripidis has. An eos iusto solet, id mel dico habemus. Oratio accumsan et mea. Eam id posse dictas voluptua, veniam laoreet oportere no mea, quis regione suscipiantur mea an. Per cu iracundia splendide. Odio contentiones sed cu, usu commodo prompta prodesset id."

void test_strlen()
{
	printf("\tft_strlen\n");
	if (ft_strlen(SIMPLE_STR) == strlen(SIMPLE_STR))
		printf("S:\t+\n");
	else
		printf("S:\t-\n");

	if (ft_strlen(EMPTY_STR) == strlen(EMPTY_STR))
		printf("E:\t+\n");
	else
		printf("E:\t-\n");

	if (ft_strlen(LONG_STR) == strlen(LONG_STR))
		printf("L:\t+\n");
	else
		printf("L:\t-\n\n");
}

void test_strdup()
{
	printf("\tft_strdup\n");
	if (strcmp(ft_strdup(SIMPLE_STR), ft_strdup(SIMPLE_STR)) == 0)
		printf("S:\t+\n");
	else
		printf("S:\t-\n");

	if (strcmp(ft_strdup(EMPTY_STR), ft_strdup(EMPTY_STR)) == 0)
		printf("E:\t+\n");
	else
		printf("E:\t-\n");

	if (strcmp(ft_strdup(LONG_STR), ft_strdup(LONG_STR)) == 0)
		printf("L:\t+\n");
	else
		printf("L:\t-\n\n");
}

void test_strcpy()
{
	char *pi;

	pi = malloc(1000);
	printf("\tft_strcpy\n");
	if (strcmp(strcpy(pi, SIMPLE_STR), ft_strcpy(pi, SIMPLE_STR)) == 0)
		printf("S:\t+\n");
	else
		printf("S:\t-\n");

	if (strcmp(strcpy(pi, EMPTY_STR), ft_strcpy(pi, EMPTY_STR)) == 0)
		printf("E:\t+\n");
	else
		printf("E:\t-\n");

	if (strcmp(strcpy(pi, LONG_STR), ft_strcpy(pi, LONG_STR)) == 0)
		printf("L:\t+\n");
	else
		printf("L:\t-\n\n");
}

void test_strcmp()
{
	printf("\tft_strcmp\n");
	if (strcmp(SIMPLE_STR, SIMPLE_STR) == 0 && ft_strcmp(SIMPLE_STR, SIMPLE_STR) == 0)
		printf("ST:\t+\n");
	else
		printf("ST:\t-\n");

	if (!(strcmp(SIMPLE_STR, LONG_STR) == 0 && ft_strcmp(SIMPLE_STR, LONG_STR) == 0))
		printf("SF:\t+\n");
	else
		printf("SF:\t-\n");

	if ((strcmp(EMPTY_STR, EMPTY_STR) == 0 && ft_strcmp(EMPTY_STR, EMPTY_STR) == 0))
		printf("ET:\t+\n");
	else
		printf("ET:\t-\n");

	if ((strcmp(SIMPLE_STR, EMPTY_STR) > 0 && ft_strcmp(SIMPLE_STR, EMPTY_STR) > 0) || (strcmp(SIMPLE_STR, EMPTY_STR) < 0 && ft_strcmp(SIMPLE_STR, EMPTY_STR) < 0))
		printf("EF:\t+\n");
	else
		printf("EF:\t-\n");

	if ((strcmp(SIMPLE_STR, LONG_STR) > 0 && ft_strcmp(SIMPLE_STR, LONG_STR) > 0) || (strcmp(SIMPLE_STR, LONG_STR) < 0 && ft_strcmp(SIMPLE_STR, LONG_STR) < 0))
		printf("LF:\t+\n");
	else
		printf("LF:\t-\n\n");

	if ((strcmp(LONG_STR, LONG_STR) == 0 && ft_strcmp(LONG_STR, LONG_STR) == 0))
		printf("LT:\t+\n");
	else
		printf("LT:\t-\n\n");
}

void	test_write()
{
	int a;
	int b;

	int er_a;
	int er_b;
	int fd = open("test.txt", O_CREAT | O_RDWR, S_IREAD | S_IWRITE);
	printf("\tft_write\n");
	a =	write(fd, LONG_STR, strlen(LONG_STR));
	er_a = errno;
	write(fd, "\n", 1);
	b = ft_write(fd, LONG_STR, strlen(LONG_STR));
	er_b = errno;
	if (a == b && er_a == er_b)
		printf("T:\t+\n");
	else
		printf("T:\t-\n");


	a =	write(101, LONG_STR, strlen(LONG_STR));
	er_a = errno;
	write(fd, "\n", 1);
	b = ft_write(101, LONG_STR, strlen(LONG_STR));
	er_b = errno;
	if (a == b && er_a == er_b)
		printf("T:\t+\n");
	else
		printf("T:\t-\n");

}

void	test_read()
{
	int a;
	int b;

	int er_a;
	int er_b;
	int fd = open("test.txt", O_CREAT | O_RDWR, S_IREAD | S_IWRITE);
	char *buf;
	buf = malloc(10);
	buf[10] = '\0';
	printf("\tft_read\n");
	a =	read(fd, buf, 10);
	er_a = errno;
	b = ft_read(fd, buf, 10);
	er_b = errno;
	if (a == b && er_a == er_b)
		printf("T:\t+\n");
	else
		printf("T:\t-\n");


	a =	read(101, buf, 10);
	er_a = errno;
	b = ft_read(101, buf, 10);
	er_b = errno;
	if (a == b && er_a == er_b)
		printf("T:\t+\n");
	else
		printf("T:\t-\n");
}

int main()
{
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	return (0);
}
