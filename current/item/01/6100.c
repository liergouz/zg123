
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("Ůװ����");
        set_picid_1(6100);
        set_picid_2(6100);
        set_unit("��");

        set_level(0);
        set_value(40);
        set_max_lasting(2599);
        set("dp", 10);

        setup();

        set_gender(2);
        set_armor_code(F_BUYI);
        set_armor_color_1(0x10e41988);
        set_armor_color_2(0x000010a3);
}

// ��������ȡ����
string get_desc()
{
        return "һ���ʺ�Ů�������ĳ�ѧ�߷��ߡ�";
}
