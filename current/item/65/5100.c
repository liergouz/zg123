
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("���׹�");
        set_picid_1(6580);
        set_picid_2(6580);

        set_level(100);
        set_value(45500);
        set_max_lasting(9699);
        set("dp", 68);
        set("pp", 113);

        setup();

        set_gender(1);
        set_head_code(47);
}

// ��������ȡ����
string get_desc()
{
        return "���׹�";
}
