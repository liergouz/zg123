
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��Ь");
        set_picid_1(8800);
        set_picid_2(8800);

        set_level(10);
        set_value(1400);
        set_max_lasting(4899);
        set("dp", 4);
        set("sp", 4);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ь";
}
