
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(90);
        set_value(21500);
        set_max_lasting(11199);
        set("dp", 43);
        set("sp", 48);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
