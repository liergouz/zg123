
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8806);
        set_picid_2(8806);

        set_level(25);
        set_value(2300);
        set_max_lasting(4999);
        set("dp", 7);
        set("sp", 9);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
