
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 66);
        set("pp", 42);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
