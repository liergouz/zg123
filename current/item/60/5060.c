
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(60);
        set_value(30500);
        set_max_lasting(9699);
        set("dp", 85);
        set("pp", 151);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
