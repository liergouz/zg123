
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("�ż�ͷ��");
        set_picid_1(6600);
        set_picid_2(6600);

        set_level(20);
        set_value(1600);
        set_max_lasting(4899);
        set("dp", 19);
        set("pp", 27);

        setup();

        set_gender(2);
        set_head_code(51);
}

// ��������ȡ����
string get_desc()
{
        return "�ż�ͷ��";
}
