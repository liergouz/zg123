
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����ñ");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(70);
        set_value(18000);
        set_max_lasting(8499);
        set("dp", 61);
        set("pp", 45);

        setup();

        set_gender(1);
        set_head_code(45);
}

// ��������ȡ����
string get_desc()
{
        return "����ñ";
}
