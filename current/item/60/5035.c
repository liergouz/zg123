
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(35);
        set_value(10500);
        set_max_lasting(6699);
        set("dp", 55);
        set("pp", 91);

        setup();

        set_gender(1);
        set_armor_code(2);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
