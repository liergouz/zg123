
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ˮͷ��");
        set_picid_1(6620);
        set_picid_2(6620);

        set_level(30);
        set_value(6000);
        set_max_lasting(6099);
        set("dp", 29);
        set("pp", 21);

        setup();

        set_gender(2);
        set_head_code(52);
}

// ��������ȡ����
string get_desc()
{
        return "��ˮͷ��";
}
