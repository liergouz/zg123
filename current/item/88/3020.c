
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ɳ��Ь");
        set_picid_1(8804);
        set_picid_2(8804);

        set_level(20);
        set_value(2000);
        set_max_lasting(5899);
        set("dp", 11);
        set("sp", 4);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ɳ��Ь";
}
