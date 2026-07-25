#include "test_hub.h"

Suite *suite_string(void);
extern TCase *tcase_s21memchr(void);
extern TCase *tcase_s21strlen(void);
extern TCase *tcase_s21strerror(void);
extern TCase *tcase_s21strstr(void);
extern TCase *tcase_s21strpbrk(void);
extern TCase *tcase_s21strcspn(void);
extern TCase *tcase_s21strncat(void);
extern TCase *tcase_s21memcmp(void);
extern TCase *tcase_s21memcpy(void);
extern TCase *tcase_s21memset(void);
extern TCase *tcase_s21strtok(void);
extern TCase *tcase_s21strchr(void);
extern TCase *tcase_s21strrchr(void);
extern TCase *tcase_s21strncmp(void);
extern TCase *tcase_s21strncpy(void);
extern TCase *tcase_s21trim(void);
extern TCase *tcase_s21to_upper(void);
extern TCase *tcase_s21sscanf(void);
extern TCase *tcase_s21insert(void);
extern TCase *tcase_s21to_lower(void);
extern TCase *tcase_s21sprintf(void);

int main() {
    Suite *container = suite_string();
    SRunner *runner = srunner_create(container);
    srunner_run_all(runner, CK_NORMAL);
    srunner_set_fork_status(runner, CK_FORK);

    int failed_cases = 0;
    failed_cases = srunner_ntests_failed(runner);

    srunner_free(runner);

    return failed_cases == 0 ? 0 : 1;
}

Suite *suite_string(void) {
    Suite *container = suite_create("s21stringlib");

    suite_add_tcase(container, tcase_s21strlen());
    suite_add_tcase(container, tcase_s21strerror());
    suite_add_tcase(container, tcase_s21memchr());
    suite_add_tcase(container, tcase_s21strstr());
    suite_add_tcase(container, tcase_s21strpbrk());
    suite_add_tcase(container, tcase_s21strcspn());
    suite_add_tcase(container, tcase_s21strncat());
    suite_add_tcase(container, tcase_s21memcmp());
    suite_add_tcase(container, tcase_s21memcpy());
    suite_add_tcase(container, tcase_s21memset());
    suite_add_tcase(container, tcase_s21strtok());
    suite_add_tcase(container, tcase_s21strchr());
    suite_add_tcase(container, tcase_s21strrchr());
    suite_add_tcase(container, tcase_s21strncmp());
    suite_add_tcase(container, tcase_s21strncpy());
    suite_add_tcase(container, tcase_s21trim());
    suite_add_tcase(container, tcase_s21to_upper());
    suite_add_tcase(container, tcase_s21sscanf());
    suite_add_tcase(container, tcase_s21insert());
    suite_add_tcase(container, tcase_s21sprintf());
    suite_add_tcase(container, tcase_s21to_lower());

    return container;
}

int sign_int(int x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }