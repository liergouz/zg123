
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6613);
        set_picid_2(6613);

        set_level(40);
        set_value(8500);
        set_max_lasting(7899);
        set("dp", 49);
        set("pp", 27);

        setup();

        set_gender(2);
        set_head_code(53);
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
