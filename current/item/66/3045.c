
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("������ñ");
        set_picid_1(6623);
        set_picid_2(6623);

        set_level(45);
        set_value(10300);
        set_max_lasting(8499);
        set("dp", 62);
        set("pp", 25);

        setup();

        set_gender(2);
        set_head_code(53);
}

// ��������ȡ����
string get_desc()
{
        return "������ñ";
}
