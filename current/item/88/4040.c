
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(40);
        set_value(6000);
        set_max_lasting(6999);
        set("dp", 10);
        set("sp", 34);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
