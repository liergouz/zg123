
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("���׹�");
        set_picid_1(6556);
        set_picid_2(6556);

        set_level(35);
        set_value(6700);
        set_max_lasting(7299);
        set("dp", 50);
        set("pp", 19);

        setup();

        set_gender(1);
        set_head_code(42);
}

// ��������ȡ����
string get_desc()
{
        return "���׹�";
}
