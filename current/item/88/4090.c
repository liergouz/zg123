
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(90);
        set_value(18500);
        set_max_lasting(11499);
        set("dp", 20);
        set("sp", 94);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
