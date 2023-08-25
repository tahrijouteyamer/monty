#include "monty.h"


void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);


/**
 * monty_add - this adds the top two values of a stack_t linked lis.
 * @stack: the pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a Monty bytecodes file
 * Description: The result is stored in the second value node
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "add"));
        return;
    }


    (*stack)->next->next->n += (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_sub - this Subtracts the second value from first
 * @stack: the pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a Monty bytecodes file
 * Description: the result is stored in the second value node
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "sub"));
        return;
    }


    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_div - this divides the second value from the first
 * @stack: a pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a Monty bytecodes file
 * Description: the result is stored in the second value
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "div"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }


    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_mul - this multiplies the second value with the first
 * @stack: the pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a Monty bytecodes file
 * Description: the result is stored in the second value node
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mul"));
        return;
    }


    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, line_number);
}


/**
 * monty_mod - this computes the modulus of the second value with first
 * @stack: the pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a Monty bytecodes file
 * Description: the ending result is stored in the second value node
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mod"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }


    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, line_number);
}
