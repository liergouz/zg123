
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;
int get_item_color() { return 1; }
// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��Ь");
        set_picid_1(8800);
        set_picid_2(8800);

        set_level(0);
        set_value(300);
        set_max_lasting(2199);
        set("dp", 2);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ь";
}
