
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(70);
        set_value(36500);
        set_max_lasting(22599);
        set("dp", 165);
        set("pp", 102);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
