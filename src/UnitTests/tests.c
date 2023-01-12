#include <stdio.h>
#include <check.h>
#include "./s21_math.h"

START_TEST(test_name)

END_TEST

Suite *example_suite_create(void) {
    Suite *suite = suite_create("Example");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, test_name);
    
    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);
    
    return suite;
}

int main(void) {
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    
    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    
    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
