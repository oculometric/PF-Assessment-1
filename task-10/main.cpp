#include <iostream>

using namespace std;

struct assessment_1_grades
{
    int c1_task_1 = 5;
    int c1_task_2 = 5;
    int c1_task_3 = 5;
    int c1_task_4 = 10;
    int c1_task_5 = 10;
    int c1_task_6 = 10;
    int c1_task_7 = 10;
    int c1_task_8 = 15;
    int c1_task_9 = 15;
    int c1_task_10 = 15;

    int c1 = 100;

    int c2 = 100;
};

struct assessment_2_grades
{
    int c1 = 100;
    int c2 = 100;
    int c3 = 100;
};

int get_assessment_1_c1_total(assessment_1_grades a1g)
{
    return a1g.c1_task_1
        + a1g.c1_task_2
        + a1g.c1_task_3
        + a1g.c1_task_4
        + a1g.c1_task_5
        + a1g.c1_task_6
        + a1g.c1_task_7
        + a1g.c1_task_8
        + a1g.c1_task_9
        + a1g.c1_task_10;
}

/*
* Returns a number between 0 and 100 for the overall grade on assignment 1
*/
float calculate_assessment_1_grade(assessment_1_grades a1g)
{
    return (0.7f * a1g.c1) + (0.3 * a1g.c2);
}

/*
* Returns a number between 0 and 100 for the overall grade on assignment 2
*/
float calculate_assessment_2_grade(assessment_2_grades a2g)
{
    return (0.6f * a2g.c1) + (0.2f * a2g.c2) + (0.2f * a2g.c3);
}

/*
* Repeatedly prompts the user for input until they behave (put in a value within the required range)
*/
int get_integer_input_from_user(string prompt, int min, int max)
{
    int r_val = min - 1;
    while (true)
    {
        cout << prompt;
        cin >> r_val;

        if (r_val < min || r_val > max)
        {
            cout << "The number you entered was out of range. Try again." << endl;
        }
        else
        {
            return r_val;
        }
    }
}

/*
* Returns a CRG band based on the percentage mark provided
*/
int get_band(float percentage)
{
    if (percentage < 30) return 0;
    if (percentage < 40) return 1;
    if (percentage < 50) return 2;
    if (percentage < 60) return 3;
    if (percentage < 70) return 4;
    return 5;
}

void main()
{
    assessment_1_grades a1g_max;
    assessment_2_grades a2g_max;

    assessment_1_grades a1g;
    assessment_2_grades a2g;

    // get assessment 1 data
    
    cout << "Please enter your marks for assessment 1, criterion 1:" << endl;

    a1g.c1_task_1 = get_integer_input_from_user("Challenge 1: ", 0, a1g_max.c1_task_1);
    a1g.c1_task_2 = get_integer_input_from_user("Challenge 2: ", 0, a1g_max.c1_task_2);
    a1g.c1_task_3 = get_integer_input_from_user("Challenge 3: ", 0, a1g_max.c1_task_3);
    a1g.c1_task_4 = get_integer_input_from_user("Challenge 4: ", 0, a1g_max.c1_task_4);
    a1g.c1_task_5 = get_integer_input_from_user("Challenge 5: ", 0, a1g_max.c1_task_5);
    a1g.c1_task_6 = get_integer_input_from_user("Challenge 6: ", 0, a1g_max.c1_task_6);
    a1g.c1_task_7 = get_integer_input_from_user("Challenge 7: ", 0, a1g_max.c1_task_7);
    a1g.c1_task_8 = get_integer_input_from_user("Challenge 8: ", 0, a1g_max.c1_task_8);
    a1g.c1_task_9 = get_integer_input_from_user("Challenge 9: ", 0, a1g_max.c1_task_9);
    a1g.c1_task_10 = get_integer_input_from_user("Challenge 10: ", 0, a1g_max.c1_task_10);

    a1g.c1 = get_assessment_1_c1_total(a1g);

    a1g.c2 = get_integer_input_from_user("Enter your mark for assessment 1, criterion 2: ", 0, a1g_max.c2);

    cout << endl;

    // get assessment 2 data

    a2g.c1 = get_integer_input_from_user("Enter your mark for assessment 2, criterion 1: ", 0, a2g_max.c1);

    a2g.c2 = get_integer_input_from_user("Enter your mark for assessment 2, criterion 2: ", 0, a2g_max.c2);

    a2g.c3 = get_integer_input_from_user("Enter your mark for assessment 2, criterion 3: ", 0, a2g_max.c3);

    cout << endl;
    
    // generate breakdown of assessment 1

    float a1_mark = calculate_assessment_1_grade(a1g);
    float a2_mark = calculate_assessment_2_grade(a2g);

    cout << "Assessment 1:" << endl;
    cout << "  Overall mark: " << a1_mark << "%" << endl;
    cout << "  Overall CRG band: " << get_band(a1_mark) << endl;
    cout << endl;
    cout << "  Criterion 1 mark: " << a1g.c1 << endl;
    cout << "  Criterion 1 CRG band: " << get_band(a1g.c1) << endl;
    cout << "  Criterion 1 details:" << endl;
    cout << "    Challenge 1: " << a1g.c1_task_1 << " / " << a1g_max.c1_task_1 << endl;
    cout << "    Challenge 2: " << a1g.c1_task_2 << " / " << a1g_max.c1_task_2 << endl;
    cout << "    Challenge 3: " << a1g.c1_task_3 << " / " << a1g_max.c1_task_3 << endl;
    cout << "    Challenge 4: " << a1g.c1_task_4 << " / " << a1g_max.c1_task_4 << endl;
    cout << "    Challenge 5: " << a1g.c1_task_5 << " / " << a1g_max.c1_task_5 << endl;
    cout << "    Challenge 6: " << a1g.c1_task_6 << " / " << a1g_max.c1_task_6 << endl;
    cout << "    Challenge 7: " << a1g.c1_task_7 << " / " << a1g_max.c1_task_7 << endl;
    cout << "    Challenge 8: " << a1g.c1_task_8 << " / " << a1g_max.c1_task_8 << endl;
    cout << "    Challenge 9: " << a1g.c1_task_9 << " / " << a1g_max.c1_task_9 << endl;
    cout << "    Challenge 10: " << a1g.c1_task_10 << " / " << a1g_max.c1_task_10 << endl;
    cout << endl;
    cout << "  Criterion 2 mark: " << a1g.c2 << endl;
    cout << "  Criterion 2 CRG band: " << get_band(a1g.c2) << endl;
    cout << endl;
    cout << endl;

    // generate breakdown of assessment 2

    cout << "Assessment 2:" << endl;
    cout << "  Overall mark: " << a2_mark << "%" << endl;
    cout << "  Overall CRG band: " << get_band(a2_mark) << endl;
    cout << endl;
    cout << "  Criterion 1 mark: " << a2g.c1 << endl;
    cout << "  Criterion 1 CRG band: " << get_band(a2g.c1) << endl;
    cout << endl;
    cout << "  Criterion 2 mark: " << a2g.c2 << endl;
    cout << "  Criterion 2 CRG band: " << get_band(a2g.c2) << endl;
    cout << endl;
    cout << "  Criterion 3 mark: " << a2g.c3 << endl;
    cout << "  Criterion 3 CRG band: " << get_band(a2g.c3) << endl;
    cout << endl;
}