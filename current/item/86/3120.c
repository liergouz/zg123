
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("߱������");
        set_picid_1(8663);
        set_picid_2(8663);

        set_level(120);
        set_value(76500);
        set_max_lasting(9699);
        set("cp", 0);
        set("pp", 115);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "߱������";
}
