
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(25);
        set_value(2500);
        set_max_lasting(6299);
        set("dp", 13);
        set("sp", 13);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
